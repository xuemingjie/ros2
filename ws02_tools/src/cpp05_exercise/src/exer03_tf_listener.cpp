/*
    需求：
    流程  
    1.包含头文件; 
    2.初始化ros2客户端; 
    3.自定义节点类; 
    4.调用spin函数，传入自定义类对象指针; 
    5.释放资源；
*/
//1.包含头文件
#include "rclcpp/rclcpp.hpp"
//  3.自定义节点类;
class Exer03TfListener: public rclcpp::Node{
public:
    Exer03TfListener():Node("exer03_tf_listener_node_cpp"){
}
};
int main(int argc, char ** argv)
{
    //2.初始化ros2客户端;
    rclcpp::init(argc,argv);
    //4.调用spin函数，传入自定义类对象指针;
    rclcpp::spin(std::make_shared<Exer03TfListener>());
    //5.释放资源;
    rclcpp::shutdown();
    return 0;
}