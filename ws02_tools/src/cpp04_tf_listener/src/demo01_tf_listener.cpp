/*
  需求：先发布laser到base_link的坐标系相对关系，再发布camera到base_link的坐标系相对关系，
        求解laser到camera的坐标系相对关系
  流程  
  1.包含头文件; 
  2.初始化ros2客户端; 
  3.自定义节点类; 
    3.1 创建一个缓存对象，融合多个坐标系相对关系为一颗坐标树
    3.2 创建一个监听器，绑定缓存对象，会将所有广播器广播的数据写入缓存
    3.3 编写一个定时器，循环实现转换
  4.调用spin函数，传入自定义类对象指针; 
  5.释放资源；
*/
//1.包含头文件
#include "rclcpp/rclcpp.hpp"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
using namespace std::chrono_literals;
//  3.自定义节点类;
class TfListener: public rclcpp::Node{
public:
  TfListener():Node("tf_listener_node_cpp"){
    // 3.1 创建一个缓存对象，融合多个坐标系相对关系为一颗坐标树
    buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
    // 3.2 创建一个监听器，绑定缓存对象，会将所有广播器广播的数据写入缓存
    listener_ = std::make_shared<tf2_ros::TransformListener>(*buffer_,this);
    // 3.3 编写一个定时器，循环实现转换
    timer_ = this->create_wall_timer(1s,std::bind(&TfListener::on_timer,this));

}
private:
  std::unique_ptr<tf2_ros::Buffer> buffer_;
  std::shared_ptr<tf2_ros::TransformListener> listener_;
  rclcpp::TimerBase::SharedPtr timer_;
  void on_timer()
  {
    //实现坐标系转换
    try
    {
     auto ts = buffer_->lookupTransform("camera","laser",tf2::TimePointZero);
     RCLCPP_INFO(this->get_logger(),"------------转换完成的坐标帧信息------------");
     RCLCPP_INFO(this->get_logger(),
        "新坐标帧：父坐标系：%s,子坐标系%s,偏移量（%.2f,%.2f,%.2f）",
        ts.header.frame_id.c_str(),
        ts.child_frame_id.c_str(),
        ts.transform.translation.x,
        ts.transform.translation.y,
        ts.transform.translation.z

     );
    }
    catch(const tf2::LookupException& e)
    {
      RCLCPP_INFO(this->get_logger(),"异常提示%s",e.what());
    }
    
  }
};
int main(int argc, char ** argv)
{
  //2.初始化ros2客户端;
  rclcpp::init(argc,argv);
  //4.调用spin函数，传入自定义类对象指针;
  rclcpp::spin(std::make_shared<TfListener>());
  //5.释放资源;
  rclcpp::shutdown();
  return 0;
}