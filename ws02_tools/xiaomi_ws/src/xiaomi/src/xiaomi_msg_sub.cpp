#include "xiaomi_interfaces/msg/xiaomi.hpp"
#include "rclcpp/rclcpp.hpp"
#include <serial/serial.h>
#include <std_msgs/msg/u_int8_multi_array.hpp>
#include "xiaomi/xiaomi.h"
#include <cmath>


using namespace std::chrono_literals;
using xiaomi_interfaces::msg::Xiaomi;

class Msg_sub_node : public rclcpp::Node{
public:
    Msg_sub_node(std::string name) :Node(name)
    {
        try {
            serialPort.setPort("/dev/ttyUSB0");
            serialPort.setBaudrate(921600);
            serial::Timeout timeout = serial::Timeout::simpleTimeout(1000);
            serialPort.setTimeout(timeout);
            serialPort.open();
            RCLCPP_INFO(this->get_logger(), "打开串口设备");
        } 
        catch (serial::IOException &e) {
            RCLCPP_INFO(this->get_logger(), "无法打开串口设备");
            return;
        }
        msg_sub1 = this->create_subscription<Xiaomi>("xiaomi_msg_1",10,std::bind(&Msg_sub_node::callback1,this,std::placeholders::_1));
        msg_sub2 = this->create_subscription<Xiaomi>("xiaomi_msg_2",10,std::bind(&Msg_sub_node::callback2,this,std::placeholders::_1));

    }

private:
    serial::Serial serialPort;
    rclcpp::Subscription<Xiaomi>::SharedPtr msg_sub1;
    rclcpp::Subscription<Xiaomi>::SharedPtr msg_sub2;

    void callback1(const Xiaomi::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(),"一号电机的位置为%f",msg->angle);
    }
    void callback2(const Xiaomi::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(),"二号电机的位置为%f",msg->angle);
    }
};


int main(int argc, char  *argv[])
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<Msg_sub_node>("msg_sub_node");
    rclcpp::spin(node);
    rclcpp::shutdown();



    return 0;
}