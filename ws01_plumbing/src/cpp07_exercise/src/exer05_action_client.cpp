/*
    需求：向动作服务端发送目标点数据，并处理响应结果
    流程  
    0.解析launch文件传入的参数；
    1.包含头文件; 
    2.初始化ros2客户端; 
    3.自定义节点类; 
        3.1创建动作客户端；
        3.2连接服务端，发送请求
        3.3处理目标值相关响应结果
        3.4处理连续反馈；
        3.5处理最终响应
    4.调用spin函数，传入自定义类对象指针; 
    5.释放资源；
*/
//1.包含头文件
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "base_interfaces_demo/action/nav.hpp"
using base_interfaces_demo::action::Nav;
using namespace std::chrono_literals;
using std::placeholders::_1;
using std::placeholders::_2;

//  3.自定义节点类;
class Exer05ActionClient: public rclcpp::Node{
public:
    Exer05ActionClient():Node("exer05_action_client_node_cpp"){
    RCLCPP_INFO(this->get_logger(),"动作客户端建立");
        // 3.1创建动作客户端；
    client_ = rclcpp_action::create_client<Nav>(this,"nav");
       
}
  ~Exer05ActionClient(){
        client_->async_cancel_all_goals();
    }
  
        // 3.2连接服务端，发送请求
        void send_goal(float x,float y,float theta)
        {
            //1.连接服务端
           if (!client_->wait_for_action_server(10s)){
                RCLCPP_INFO(this->get_logger(),"服务连接超时");
                return;
           }
            //2.组织并发送数据
            Nav::Goal goal;
            goal.goal_x = x;
            goal.goal_y = y;
            goal.goal_thrta=theta;
            rclcpp_action::Client<Nav>::SendGoalOptions options;
            //std::function<void (std::shared_ptr<rclcpp_action::ClientGoalHandle<base_interfaces_demo::action::Nav>>)> rclcpp_action::Client<base_interfaces_demo::action::Nav>::SendGoalOptions::goal_response_callback
            options.goal_response_callback = std::bind(&Exer05ActionClient::goal_response_callback,this,_1);
            //std::function<void (std::shared_ptr<rclcpp_action::ClientGoalHandle<base_interfaces_demo::action::Nav>>, std::shared_ptr<const base_interfaces_demo::action::Nav_Feedback>)> rclcpp_action::Client<base_interfaces_demo::action::Nav>::SendGoalOptions::feedback_callback
            options.feedback_callback = std::bind(&Exer05ActionClient::feedback_callback,this,_1,_2);
            //std::function<void (const rclcpp_action::ClientGoalHandle<base_interfaces_demo::action::Nav>::WrappedResult &result)> rclcpp_action::Client<base_interfaces_demo::action::Nav>::SendGoalOptions::result
            options.result_callback =  std::bind(&Exer05ActionClient::result_callback,this,_1);
            client_->async_send_goal(goal,options);

        }

        // 3.3处理目标值相关响应结果
        void goal_response_callback(std::shared_ptr<rclcpp_action::ClientGoalHandle<Nav>> goal_handle){
            if (!goal_handle)
            {
                RCLCPP_INFO(this->get_logger(),"请求目标非法！");
            }else{
                RCLCPP_INFO(this->get_logger(),"目标被接收");
                
            }

        }
        // 3.4处理连续反馈；
        void feedback_callback(std::shared_ptr<rclcpp_action::ClientGoalHandle<Nav>> goal_hancle, std::shared_ptr<const Nav::Feedback > feedback){
            (void)goal_hancle;
            RCLCPP_INFO(this->get_logger(),"剩余距离%.2f米",feedback->distance);
        }
        // 3.5处理最终响应
        void result_callback (const rclcpp_action::ClientGoalHandle<Nav>::WrappedResult &result){
            if(result.code == rclcpp_action::ResultCode::SUCCEEDED){

            RCLCPP_INFO(this->get_logger(),"乌龟的位姿信息，坐标:(%.2f,%.2f),航向:%.2f)",result.result->turtle_x,result.result->turtle_y,result.result->turtle_theta);
           
            
          }
          else if(result.code == rclcpp_action::ResultCode::ABORTED){
            RCLCPP_INFO(this->get_logger(),"被中断！");
          }
          else if(result.code == rclcpp_action::ResultCode::CANCELED){
            RCLCPP_INFO(this->get_logger(),"被取消！");
          }
          else if(result.code == rclcpp_action::ResultCode::UNKNOWN){
            RCLCPP_INFO(this->get_logger(),"未知异常");
          }

        }
private:
    rclcpp_action::Client<Nav>::SharedPtr client_;
    
};
int main(int argc, char ** argv)
{
    // 0.解析launch文件传入的参数
    if (argc != 5)
    {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"请输入合法的目标点数据");
        return -1;
    }

    //2.初始化ros2客户端;
    rclcpp::init(argc,argv);
    //4.调用spin函数，传入自定义类对象指针;
    auto client = std::make_shared<Exer05ActionClient>();
    client->send_goal(atof(argv[1]),atof(argv[2]),atof(argv[3]));

    rclcpp::spin(client);
    rclcpp::shutdown();
    return 0;
}