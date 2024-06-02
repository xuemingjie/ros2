#include "rclcpp/rclcpp.hpp"
#include "base_interfaces_demo/msg/student.hpp"

using namespace std::chrono_literals;

class TalkerStu: public rclcpp::Node{
    public:
    TalkerStu():Node("talkerstu_node_cpp"),count(0),age(0)
    {

        RCLCPP_INFO(this->get_logger(),"发布者节点已创建");
        puber_ = this->create_publisher<base_interfaces_demo::msg::Student>("chatter",10);
        timer_= this->create_wall_timer(1s,std::bind(&TalkerStu::do_time,this));


    }
    private:
    void do_time()
    {
        auto msg = base_interfaces_demo::msg::Student();
        msg.name = "huluwa";
        msg.age = age;
        msg.height = 2.20;
        age++;
        puber_->publish(msg);
        RCLCPP_INFO(this->get_logger(),"发布的消息：（%s,%d,%.2f) ",msg.name.c_str(),msg.age,msg.height);
    }
        rclcpp::Publisher<base_interfaces_demo::msg::Student>::SharedPtr puber_;
        size_t count;
        rclcpp::TimerBase::SharedPtr timer_;
        int age;
};


int main(int argc, char const *argv[])
{
    rclcpp::init(argc,argv);

    rclcpp::spin(std::make_shared<TalkerStu>());


    rclcpp::shutdown();


    return 0;
}
