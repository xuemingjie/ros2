#include "xiaomi_interfaces/msg/xiaomi.hpp"
#include "rclcpp/rclcpp.hpp"
#include <serial/serial.h>
#include <std_msgs/msg/u_int8_multi_array.hpp>
#include "xiaomi/xiaomi.h"
#include <cmath>

using namespace std::chrono_literals;

class Msg_pub_node : public rclcpp::Node{

public:
    Msg_pub_node(std::string name) : Node(name){
       RCLCPP_INFO(this->get_logger(), "发布者节点建立");

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
        msg_pub1 = this->create_publisher<xiaomi_interfaces::msg::Xiaomi>("xiaomi_msg_1",10);
        msg_pub2 = this->create_publisher<xiaomi_interfaces::msg::Xiaomi>("xiaomi_msg_2",10);
        timer_ = this->create_wall_timer(1ms,std::bind(&Msg_pub_node::callback_time,this));



    }
private:
        serial::Serial serialPort;
        rclcpp::Publisher<xiaomi_interfaces::msg::Xiaomi>::SharedPtr msg_pub1;
        rclcpp::Publisher<xiaomi_interfaces::msg::Xiaomi>::SharedPtr msg_pub2;
        rclcpp::TimerBase::SharedPtr timer_;


        void callback_time()
        {
           std::vector<uint8_t> receivedData;
            bool packetComplete = false;

            while (!packetComplete)
            {
                uint8_t byte;
                serialPort.read(&byte, 1);
                receivedData.push_back(byte);

                if (receivedData.size() >= 2 &&
                    receivedData[receivedData.size() - 2] == 0x0D &&
                    receivedData[receivedData.size() - 1] == 0x0A)
                {
                    packetComplete = true;
                }
            }
            uint16_t combinedValue = (receivedData[7] << 8) | receivedData[8];
            xiaomi_interfaces::msg::Xiaomi msg;
             
            if(receivedData[4] == 0x08)
            {
                msg.id = 1;
                msg.angle =  8*M_PI/65536*combinedValue - 4*M_PI;

                // ROS_INFO("Combined value: %f", msg1.angle);
                msg_pub1->publish(msg);
            // }
            }
            else if(receivedData[4] == 0x10)
            {
                msg.id = 2;
                msg.angle =  8*M_PI/65536*combinedValue - 4*M_PI;

                // ROS_INFO("Combined value: %f", msg1.angle);
                msg_pub2->publish(msg);


            }

        }
};

int main(int argc, char  *argv[])
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<Msg_pub_node>("msg_pub_node");
    rclcpp::spin(node);
    rclcpp::shutdown();



    return 0;
}
