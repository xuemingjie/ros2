/*
    需求：启动turtlesim_node 节点，编写程序，发布乌龟（turtle1)相对于窗体（world）的位姿
    流程  
    1.包含头文件; 
    2.初始化ros2客户端; 
    3.自定义节点类; 
        3.1 创建一个动态广播器
        3.2 创建一个乌龟位姿订阅方
        3.3 回调函数中，获取乌龟位姿并生成相对关系然后发布
    4.调用spin函数，传入自定义类对象指针; 
    5.释放资源；
*/
//1.包含头文件
#include "rclcpp/rclcpp.hpp"
#include "tf2_ros/transform_broadcaster.h"
#include "turtlesim/msg/pose.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "tf2/LinearMath/Quaternion.h"
//  3.自定义节点类;
class TfDynaBroadcaster: public rclcpp::Node{
public:
    TfDynaBroadcaster():Node("tf_dyna_broadcaster_node_cpp"){
        // 3.1 创建一个动态广播器
        broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);
        // 3.2 创建一个乌龟位姿订阅方
        sub_ = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose",10,std::bind(&TfDynaBroadcaster::do_pose,this,std::placeholders::_1));

        // 3.3 回调函数中，获取乌龟位姿并生成相对关系然后发布
}
private:
    std::shared_ptr<tf2_ros::TransformBroadcaster> broadcaster_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr sub_;
    void do_pose(const turtlesim::msg::Pose & pose)
    {
        //组织消息
        geometry_msgs::msg::TransformStamped ts;
        ts.header.stamp = this->now();
        ts.header.frame_id = "world";
        ts.child_frame_id = "turtle1";

        ts.transform.translation.x = pose.x;
        ts.transform.translation.y = pose.y;
        ts.transform.translation.z = 0.0;

        //从欧拉角转换出四元数
        //乌龟的欧拉角只有yaw上的取值，没有roll和pith；
        tf2::Quaternion qut;
        qut.setRPY(0,0,pose.theta);

        ts.transform.rotation.x = qut.x();
        ts.transform.rotation.y = qut.y();
        ts.transform.rotation.z = qut.z();
        ts.transform.rotation.w = qut.w();




        //发布
        broadcaster_->sendTransform(ts);
    }
};
int main(int argc, char ** argv)
{
    //2.初始化ros2客户端;
    rclcpp::init(argc,argv);
    //4.调用spin函数，传入自定义类对象指针;
    rclcpp::spin(std::make_shared<TfDynaBroadcaster>());
    //5.释放资源;
    rclcpp::shutdown();
    return 0;
}