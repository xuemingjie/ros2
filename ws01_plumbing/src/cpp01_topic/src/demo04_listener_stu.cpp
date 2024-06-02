#include "rclcpp/rclcpp.hpp"
#include "base_interfaces_demo/msg/student.hpp"

class ListernStu: public rclcpp::Node
{

    public:
    ListernStu():Node("listernstu_node_cpp")
    {
        RCLCPP_INFO(this->get_logger(),"订阅者节点已建立");

        suber_ = this->create_subscription<base_interfaces_demo::msg::Student>("chatter",10,std::bind(&ListernStu::sub_cb,this,std::placeholders::_1));



    }
    private:
    void sub_cb(const base_interfaces_demo::msg::Student &msg)
    {
        RCLCPP_INFO(this->get_logger(),"订阅的数据是(姓名： %s,年龄： %d,身高： %.2f)",msg.name.c_str(),msg.age,msg.height);

    }
    rclcpp::Subscription<base_interfaces_demo::msg::Student>::SharedPtr suber_;

};




int main(int argc, char const *argv[])
{
    rclcpp::init(argc,argv);

    rclcpp::spin(std::make_shared<ListernStu>());


    rclcpp::shutdown();


    return 0;
}
