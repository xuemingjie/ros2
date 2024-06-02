/*
需求： 以某个固定频率发送文本“hello world!",文本后缀编号
流程
    1.包含头文件
    2.初始化ros2客户端
    3.自定义节点类
      3.1创建消息发布方
      3.2创建定时器
      3.3组织并发布消息
    4.调用spin函数，传入自定义类对象指针

    释放资源；


*/

    //1.包含头文件
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

//  3.自定义节点类

class Talker:public rclcpp::Node{
    public:
      Talker():Node("talker_node_cpp"),count(0){
        RCLCPP_INFO(this->get_logger(),"发布节点创建");
          // 3.1创建消息发布方
          /*
            模板： 被发布的消息类型
            参数  
              1.话题名称 
              2.QOS（消息队列长度）。
            返回值： 发布对象指针。      
          */
         publisher_ = this->create_publisher<std_msgs::msg::String>("chatter",10);
          // 3.2创建定时器
         timer_ = this ->create_wall_timer(1s,std::bind(&Talker::on_time,this));
          
      }
    private:
    void on_time()
    {
        // 3.3组织并发布消息
        auto message = std_msgs::msg::String();
        message.data = "hello world" + std::to_string(count++);
        RCLCPP_INFO(this->get_logger(),"发布的消息 :%s",message.data.c_str());
        publisher_->publish(message);
    }
      rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
      rclcpp::TimerBase::SharedPtr timer_;
      size_t count;
};



int main(int argc, char ** argv)
{
  //2.初始化ros2客户端
  rclcpp::init(argc,argv);

  //调用spin函数，传入自定义类对象指针
  rclcpp::spin(std::make_shared<Talker>());

  rclcpp::shutdown();
  return 0;

}
