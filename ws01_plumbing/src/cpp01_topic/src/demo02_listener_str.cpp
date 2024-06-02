
    /*  
    需求：订阅发布方的消息，并在终端输出。
    流程    
            1.包含头文件 
            2.初始化ros2客户端

            3.自定义节点类
                3.1 创建一个订阅方；
                3.2 解析并输出数据
            4.调用spin函数并传入节点对象指针
            5,资源释放
   
  
   */

 // 1.包含头文件
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"


    // 3.自定义节点类

class Listener: public rclcpp::Node{

   public:
    Listener():Node("Listern_node_cpp")
    {
        RCLCPP_INFO(this->get_logger(),"订阅方创建");
          //3.1 创建一个订阅方；
          /*
          模板：消息类型
          参数：
            1.话题名称
            2.qos（队列长度）
            3.绑定回调函数；
          返回值
            1.订阅对象指针；
          
          */
     subscription_=this->create_subscription<std_msgs::msg::String>("chatter",10,std::bind(&Listener::do_cb,this,std::placeholders::_1));

    }   
     private:
    void do_cb(const std_msgs::msg::String::SharedPtr msg)
    {
            //3.2 解析并输出数据
            RCLCPP_INFO(this->get_logger(),"订阅到的消息是%s",msg->data.c_str());
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;


};
int main(int argc, char const *argv[])
{
        // 2.初始化ros2客户端
        rclcpp::init(argc,argv);

         //4.调用spin函数并传入节点对象指针
         rclcpp::spin(std::make_shared<Listener>());
    
            // 5,资源释放
        rclcpp::shutdown();
    return 0;
}
