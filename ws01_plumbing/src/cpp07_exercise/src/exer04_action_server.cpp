/*
    需求：处理客户端发送的数据（目标点），控制乌龟向目标点运动，且要连续反馈剩余距离
    流程  
    1.包含头文件; 
    2.初始化ros2客户端; 
    3.自定义节点类; 
        3.1 创建原生乌龟位姿订阅方，获取当前乌龟坐标；
        3.2 创建速度指令发布方，控制乌龟的运动
        3.3 创建一个动作服务端；
        3.4 解析动作客户端提交的数据；
        3.5 处理客户端取消请求操作；
        3.6 实现主逻辑（耗时操作），启动子线程；
        3.7 在子线程中，发布速度指令，产生连续反馈，响应最终结果；
    4.调用spin函数，传入自定义类对象指针; 
    5.释放资源；
*/
//1.包含头文件
#include "rclcpp/rclcpp.hpp"
#include "turtlesim/msg/pose.hpp"
#include "base_interfaces_demo/action/nav.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

using turtlesim::msg::Pose;
using base_interfaces_demo::action::Nav;
using geometry_msgs::msg::Twist;
using std::placeholders::_1;
using std::placeholders::_2;
using namespace std::chrono_literals;
//  3.自定义节点类;
class Exer04ActionServe: public rclcpp::Node{
public:
    Exer04ActionServe():Node("exer04_action_serve_node_cpp"),x(0.0),y(0.0){
    RCLCPP_INFO(this->get_logger(),"动作服务端建立");
        // 3.1 创建原生乌龟位姿订阅方，获取当前乌龟坐标；
        sub_ = this->create_subscription<Pose>("/turtle1/pose",10,std::bind(&Exer04ActionServe::pose_cb,this,_1));
        // 3.2 创建速度指令发布方，控制乌龟的运动
        pub_ = this->create_publisher<Twist>("/turtle1/cmd_vel",10);
        // 3.3 创建一个动作服务端；
         /*
         NodeT node, 
         const std::string &name, rclcpp_action::Server<ActionT>::GoalCallback handle_goal,
         rclcpp_action::Server<ActionT>::CancelCallback handle_cancel, 
         rclcpp_action::Server<ActionT>::AcceptedCallback handle_accepted
         */
        action_server_ = rclcpp_action::create_server<Nav>(
            this,
            "nav",
            std::bind(&Exer04ActionServe::handle_goal,this,_1,_2),
            std::bind(&Exer04ActionServe::handle_cancel,this,_1),
            std::bind(&Exer04ActionServe::handle_accept,this,_1)
            );

            
        // 3.4 解析动作客户端提交的数据；
        // 3.5 处理客户端取消请求操作；
        // 3.6 实现主逻辑（耗时操作），启动子线程；
        // 3.7 在子线程中，发布速度指令，产生连续反馈，响应最终结果；
    
}
private:
    rclcpp::Subscription<Pose>::SharedPtr sub_;
    rclcpp::Publisher<Twist>::SharedPtr pub_;
    rclcpp_action::Server<Nav>::SharedPtr action_server_;
    float x,y;
    void pose_cb(const Pose::SharedPtr pose)
    {
        x = pose->x;
        y = pose->y;
    }

    rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const typename Nav::Goal> goal){
        (void)uuid;
        
        //取出目标中的x y坐标，分别判断是否超出了（0,11.98），如果超出，则认为非法，否则合法
        if(goal->goal_x < 0 || goal->goal_x > 11.08 || goal->goal_y < 0 || goal->goal_y > 11.08){
            RCLCPP_INFO(this->get_logger(),"目标点超出正常取决范围了");
            return rclcpp_action::GoalResponse::REJECT;
        }
        RCLCPP_INFO(this->get_logger(),"目标点合法");
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }
    rclcpp_action::CancelResponse handle_cancel(std::shared_ptr<rclcpp_action::ServerGoalHandle<Nav>> goal_hancle){
        (void)goal_hancle;
        RCLCPP_INFO(this->get_logger(),"取消任务");
        return rclcpp_action::CancelResponse::ACCEPT;
    }
    void execute(std::shared_ptr<rclcpp_action::ServerGoalHandle<Nav>> goal_handle){
        //子线程处理主要逻辑
        RCLCPP_INFO(this->get_logger(),"主逻辑开始执行！");
        //最终结果
        auto result = std::make_shared<Nav::Result>();
        auto feedback = std::make_shared<Nav::Feedback>();
        Twist twist;
        //1.生成连续反馈
        rclcpp::Rate rate(1.0);
        while (true)
        {
            //如果要取消任务，需要特殊处理
            if(goal_handle->is_canceling()){
                //设置取消后的最终结果
                goal_handle->canceled(result);
                return;
            }

            //解析目标点坐标与原生乌龟实时坐标
            float goal_x = goal_handle->get_goal()->goal_x;
            float goal_y = goal_handle->get_goal()->goal_y;

            //计算剩余距离并发布
            float distance_x = goal_x - x;
            float distance_y = goal_y - y;
            float distance = std::sqrt(distance_x*distance_x + distance_y*distance_y);
            feedback->distance = distance;
            goal_handle->publish_feedback(feedback);
             //2.发布乌龟运动指令
            //根据剩余距离计算速度指令并发布
            float scale = 0.5;
            float linear_x = scale * distance_x;
            float linear_y = scale * distance_y;
            twist.linear.x = linear_x;
            twist.linear.y = linear_y;
            pub_ ->publish(twist);
            //循环结束条件
            if(distance<=0.05){
                //与目标点的剩余距离小于0.05米，就结束导航
                RCLCPP_INFO(this->get_logger(),"已经导航至目标点");
                break;
            }
            rate.sleep();
        }
        //3.生成最终响应
        if(rclcpp::ok()){
        result->turtle_x = x;
        result->turtle_y = y;
        goal_handle->succeed(result);
        }

        

    }
    void handle_accept(std::shared_ptr<rclcpp_action::ServerGoalHandle<Nav>> goal_handle){
        std::thread(std::bind(&Exer04ActionServe::execute,this,goal_handle)).detach();
        
    }

};
int main(int argc, char ** argv)
{
//2.初始化ros2客户端;
rclcpp::init(argc,argv);
//4.调用spin函数，传入自定义类对象指针;
rclcpp::spin(std::make_shared<Exer04ActionServe>());
//5.释放资源;
rclcpp::shutdown();
return 0;
}