/*
需求：创建客户端，组织数据并提交，然后处理响应结果
流程：
    前提：main中判断提交的参数是否正确

    1.包含头文件
    2.初始化ROS2客户端
    3.自定义节点类
        3.1创建客户端
        3.2连接服务器（对于服务通信而言，如果客户端连接不到服务器，那么不能发送请求
        3.3发送请求
    4.创建对象指针
        需要调用连接服务器的函数，根据连接结果作下一步处理
        连接服务器后，调用请求发送函数
        再处理响应结果
    5.资源释放

*/
#include "rclcpp/rclcpp.hpp"
#include "base_interfaces_demo/srv/addints.hpp"
using base_interfaces_demo::srv::Addints;
using namespace std::chrono_literals;
class AddintsClient : public rclcpp::Node
{

 public:
  AddintsClient():Node("addints_clinet_node_cpp")
  {
      RCLCPP_INFO(this->get_logger(),"客户端节点创建");
      client_ = this->create_client<Addints>("addints");
  }
  //连接服务器函数！！！！！
  bool connect_server()
  {
    //client_->wait_for_service(1s);
    //超过一秒还连接不上，返回false
    while (!client_->wait_for_service(1s))
    {
        /* 循环以1s为超时时间连接服务器，直到连接成功，退出循环 */
        //会发现ctrl+c会变成死循环，对它作出处理
        if (!rclcpp::ok())
        {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"强行终止客户端");
            return false;
        }
        
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"服务连接中");
    }
    
    return true;
  }

  //编写发送请求函数！！！！
  
  /*
rclcpp::Client<base_interfaces_demo::srv::Addints>::FutureAndRequestId 
async_send_request(std::shared_ptr<base_interfaces_demo::srv::Addints_Request> request)
  */
rclcpp::Client<Addints>::FutureAndRequestId send_request(int num1,int num2)
  {
        auto request = std::make_shared<Addints::Request>();
        request->num1 = num1;
        request->num2 = num2;
       return client_->async_send_request(request);
  }
 private:
    rclcpp::Client<Addints>::SharedPtr client_;
};



int main(int argc, char  *argv[])
{

    if(argc != 3)
    {   
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"),"请提交两个整形数字");
        //除了节点输出日至，还有rclcpp::get_logger("NAME")
        return 1;
    }
  rclcpp::init(argc,argv);

  //rclcpp::spin(std::make_shared<AddintsClient>());不需要回旋函数；
  auto client = std::make_shared<AddintsClient>();
  //调用服务器连接
  bool flag = client->connect_server();
  if(!flag)
  {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"),"服务器连接失败，程序退出");
    //化重点，这里为什么不用client->get_logger();因为ctrl+c 会释放context容器，clinet都不存在了。
    return 0;
  }

  //调用请求提交函数，接受并处理相应结果
  auto future = client->send_request(atoi(argv[1]),atoi(argv[2]));


  //处理响应
  if (rclcpp::spin_until_future_complete(client,future) == rclcpp::FutureReturnCode::SUCCESS)//成功
  {
    RCLCPP_INFO(client->get_logger(),"响应成功！ sum =%d",future.get()->sum);
  }
  else//失败
  {
    RCLCPP_INFO(client->get_logger(),"响应失败");
  }
  


  rclcpp::shutdown();

  return 0;
}
