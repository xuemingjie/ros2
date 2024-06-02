/*
需求：编写服务端实现，解析提交的请求数据，并将解析的数据相加并响应到客户端
    流程：
      1.包含头文件
      2.初始化ROS2客户端
      3.自定义节点类
        3.1 创建服务端
        3.2 回调函数解析请求并发送响应
      4.调用spin函数，并传入节点指针
      5.释放资源
*/
#include "rclcpp/rclcpp.hpp"
#include "base_interfaces_demo/srv/addints.hpp"
using base_interfaces_demo::srv::Addints;
using std::placeholders::_1;
using std::placeholders::_2;

class AddintsServer : public rclcpp::Node
{

 public:
  AddintsServer():Node("addints_server_node_cpp")
  {
      RCLCPP_INFO(this->get_logger(),"服务端节点创建");
       server_ = this->create_service<Addints>("addints",std::bind(&AddintsServer::ser_cb,this,_1,_2));
    //   this->create_service<Addints>("addints",std::bind(&AddintsClient::ser_cb,this,std::placeholders::_1,std::placeholders::_2));
  }
  
 private:
 void ser_cb(const Addints::Request::SharedPtr req,const Addints::Response::SharedPtr res )
 {
    res->sum =req->num1 + req->num2;
    RCLCPP_INFO(this->get_logger(),"%d + %d = %d",req->num1,req->num2,res->sum);
    
 }
    rclcpp::Service<Addints>::SharedPtr server_;

};



int main(int argc, char  *argv[])
{
  
  rclcpp::init(argc,argv);

  rclcpp::spin(std::make_shared<AddintsServer>());


  rclcpp::shutdown();

  return 0;
}
