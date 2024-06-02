/*
  需求：订阅乌龟1的位姿信息，解析出线速度和角速度，生成并发布控制乌龟2运动的速度指令。
  明确：
        订阅话题：/turtle1/pose
        订阅消息：turtlesim/msg/Pose
                float32 x
                float32 y
                float32 theta

                float32 linear_velocity
                float32 angular_velocity
        发布话题：/t2/turtle1/cmd_vel
        发布消息：geometry_msgs/msg/Twist
                  Vector3  linear
                  float64 x
                  float64 y
                  float64 z
                Vector3  angular
                  float64 x
                  float64 y
                  float64 z
*/
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"



class Exer01PubSub : public rclcpp::Node{

public:
    Exer01PubSub():Node("exer01_pub_sub_node_cpp"){

      RCLCPP_INFO(this->get_logger(),"案例1对象创建");
      // 3.1创建发布方
      pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/t2/turtle1/cmd_vel",10);
      // 3.2创建订阅方（订阅乌龟1的位姿，解析速度）
      sub_ = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose",10,std::bind(&Exer01PubSub::pose_cb,this,std::placeholders::_1));
    }
    ~Exer01PubSub(){}
private:
    void pose_cb(const turtlesim::msg::Pose & pose)
    {
        // 3.3订阅方的回调函数，处理速度，生成并发布控制乌龟2的速度指令
        //创建速度指令
        geometry_msgs::msg::Twist twist;
        twist.linear.x = pose.linear_velocity;
        twist.angular.z = -pose.angular_velocity;
        //发布
        pub_->publish(twist);
    }
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr sub_;



};


int main(int argc, char *argv[])
{
  rclcpp::init(argc,argv);

  rclcpp::spin(std::make_shared<Exer01PubSub>());

  rclcpp::shutdown();
  return 0;
}
