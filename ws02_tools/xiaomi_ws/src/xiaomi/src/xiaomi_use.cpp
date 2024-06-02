#include "rclcpp/rclcpp.hpp"
#include "serial/serial.h"
#include "xiaomi/xiaomi.h"
#include <cmath>
#include <chrono>

using namespace std::chrono_literals;

class Xiaomi_Use_Node : public rclcpp::Node {
public:
    Xiaomi_Use_Node(std::string name) : Node(name),t(0){
        RCLCPP_INFO(this->get_logger(), "发布者节点建立");

        try {
            serialPort.setPort("/dev/ttyUSB0");
            serialPort.setBaudrate(921600);
            serial::Timeout timeout = serial::Timeout::simpleTimeout(1000);
            serialPort.setTimeout(timeout);
            serialPort.open();
            RCLCPP_INFO(this->get_logger(), "打开串口设备");
        } catch (serial::IOException &e) {
            RCLCPP_INFO(this->get_logger(), "无法打开串口设备");
            return;
        }

        xiaomi_set xiaomi_no1;
        xiaomi_set xiaomi_no2;
        initinalXiaomiSets(xiaomi_no1, 1);//初始化NO.1
        //initinalXiaomiSets(xiaomi_no2, 2);//初始化NO.2
        serialPort.write(xiaomi_no1.mode_set_1.data);//1号电机模式
        //serialPort.write(xiaomi_no2.mode_set_2.data);//2号电机模式

        xiaomi_pub = this->create_publisher<std_msgs::msg::UInt8MultiArray>("xiaomi_tx", 10);
        timer_ = this->create_wall_timer(0.1s, std::bind(&Xiaomi_Use_Node::timer_callback,this));
    }

private:
    rclcpp::Publisher<std_msgs::msg::UInt8MultiArray>::SharedPtr xiaomi_pub;
    rclcpp::TimerBase::SharedPtr timer_;
    serial::Serial serialPort;
    std_msgs::msg::UInt8MultiArray local_msg_1;
    std_msgs::msg::UInt8MultiArray speed_msg_1;
    std_msgs::msg::UInt8MultiArray cur_msg_1;
    std_msgs::msg::UInt8MultiArray local_msg_2;
    std_msgs::msg::UInt8MultiArray speed_msg_2;
    std_msgs::msg::UInt8MultiArray cur_msg_2;
    double t;

    void timer_callback() {
        //位置模式正弦示范
        float loc1 =  2 * sin(t);
        //float loc2 = -2 * cos(t);

        mode_set(1, loc1, 2, 24.0, local_msg_1, speed_msg_1, cur_msg_1);
        //mode_set(2, loc2, 2, 24.0, local_msg_2, speed_msg_2, cur_msg_2);

        xiaomi_pub->publish(local_msg_1);
        //xiaomi_pub->publish(local_msg_2);
        xiaomi_pub->publish(speed_msg_1);
        //xiaomi_pub->publish(speed_msg_2);
        xiaomi_pub->publish(cur_msg_1);
        //xiaomi_pub->publish(cur_msg_2);

        t+=0.1;


        //速度模式 速度+-10rad/s 电流限制23A

        // mode_set(1,  10, 23.0, speed_msg_1, cur_msg_1);
        // mode_set(2,  -10, 23.0, speed_msg_2, cur_msg_2);
        // xiaomi_pub->publish(speed_msg_1);
        // xiaomi_pub->publish(speed_msg_2);
        // xiaomi_pub->publish(cur_msg_1);
        // xiaomi_pub->publish(cur_msg_2);



    }
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Xiaomi_Use_Node>("xiaomi_use_node");
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}
