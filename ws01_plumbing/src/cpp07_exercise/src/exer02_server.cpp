/*
    需求：解析客户端提交的目标点坐标，获取原生乌龟坐标，计算二者距离，并响应回客户端
    流程  
    1.包含头文件; 
    2.初始化ros2客户端; 
    3.自定义节点类; 
        3.1 创建一个订阅方（原生乌龟位姿 /turtle1/pose)
        3.2 创建一个服务端
        3.3 回调函数需要解析客户端数据并响应结果到客户端
    4.调用spin函数，传入自定义类对象指针; 
    5.释放资源；
*/
//1.包含头文件
#include "rclcpp/rclcpp.hpp"
#include "turtlesim/msg/pose.hpp"
#include "base_interfaces_demo/srv/distance.hpp"

using std::placeholders::_1;
using std::placeholders::_2;
using base_interfaces_demo::srv::Distance;
//  3.自定义节点类;
class Exer02Server: public rclcpp::Node{
public:
    Exer02Server():Node("exer02_server_node_cpp"),x(0.0),y(0.0){
        RCLCPP_INFO(this->get_logger(),"案例2服务端创建了!");
        // 3.1 创建一个订阅方（原生乌龟位姿 /turtle1/pose)
        sub_ = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose",10,std::bind(&Exer02Server::pose_cb,this,_1));
        // 3.2 创建一个服务端
        server_ = this->create_service<Distance>("distance",std::bind(&Exer02Server::distance_cb,this,_1,_2));
        // 3.3 回调函数需要解析客户端数据并响应结果到客户端 
    }
private:
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr sub_;
    rclcpp::Service<Distance>::SharedPtr server_;
    float x,y;
    void pose_cb(const turtlesim::msg::Pose::SharedPtr pose){
       x = pose->x;
       y = pose->y;
    }
    void distance_cb(const Distance::Request::SharedPtr req, const Distance::Response::SharedPtr res)
    {
        //1.解析出目标点坐标
        float goal_x = req->x;
        float goal_y = req->y;
        //2.计算距离
        float distance_x = goal_x - x;
        float distance_y = goal_y - y;
        float distance = std::sqrt(distance_x* distance_x + distance_y * distance_y);
        //3.设置进响应
        res->distance = distance;
        RCLCPP_INFO(this->get_logger(),"目标点左边(%.2f,%.2f),原生乌龟坐标（%.2f,%.2f), 二者距离%.2f",
        goal_x,goal_y,x,y,distance);

    }
};
int main(int argc, char ** argv)
{
//2.初始化ros2客户端;
rclcpp::init(argc,argv);
//4.调用spin函数，传入自定义类对象指针;
rclcpp::spin(std::make_shared<Exer02Server>());
//5.释放资源;
rclcpp::shutdown();
return 0;
}