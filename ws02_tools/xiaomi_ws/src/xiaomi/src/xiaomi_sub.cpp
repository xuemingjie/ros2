#include "rclcpp/rclcpp.hpp"
#include "serial/serial.h"
#include "xiaomi/xiaomi.h"
using namespace std::chrono_literals;
serial::Serial serialPort;

class Xiaomi_Sub_Node  : public rclcpp::Node{

public:
    Xiaomi_Sub_Node(std::string name) : Node(name){

        RCLCPP_INFO(this->get_logger(), "订阅者节点建立");
        try
        {
            
            serialPort.setPort("/dev/ttyUSB0");
            serialPort.setBaudrate(921600);
            serial::Timeout _time = serial::Timeout::simpleTimeout(1000);
            serialPort.setTimeout(_time);
            serialPort.open();
            RCLCPP_INFO(rclcpp::get_logger("relcpp"),"打开串口设备");
        }
        catch (serial::IOException &e)
        {
            RCLCPP_INFO(rclcpp::get_logger("relcpp"),"无法打开串口设备");
            return ;
        }
            xiaomi_sub = this->create_subscription<std_msgs::msg::UInt8MultiArray>("xiaomi_tx",10,std::bind(&Xiaomi_Sub_Node::callback,this,std::placeholders::_1));
    }
private:
    void callback(const std_msgs::msg::UInt8MultiArray::SharedPtr msg)
    {
        serialPort.write(msg->data);
    }
    rclcpp::Subscription<std_msgs::msg::UInt8MultiArray>::SharedPtr xiaomi_sub;
    serial::Serial serialPort;

};




int main(int argc, char  *argv[])
{

   
    
    rclcpp::init(argc,argv);
    auto node = std::make_shared<Xiaomi_Sub_Node>("xiaomi_sub_node");
    rclcpp::spin(node);
    rclcpp::shutdown();


    return 0;
}
