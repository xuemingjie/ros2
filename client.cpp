#include "rclcpp/rclcpp.hpp"
#include "base_interfaces_demo/srv/addints.hpp"

using base_interfaces_demo::srv::Addints;
using namespace std::chrono_literals;

class Client : public rclcpp::Node{
public:
    Client():Node("client_node"){
        RCLCPP_INFO(this->get_logger(),"客户端节点建立");
        client_ = this->create_client<Addints>("lianxi");
    }
    bool service_connect(){
        int count = 0;
        while (!client_->wait_for_service(1s))
        {
            if(!rclcpp::ok())
            {
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"主动结束客户端");
                return false;
            }
            count ++;
            RCLCPP_INFO(this->get_logger(),"等待服务器连接中%d",count);
        }
        return true;
        
    }
    rclcpp::Client<Addints>::FutureAndRequestId send_request (int num1,int num2){

        auto request = std::make_shared<Addints::Request>();
         request->num1 = num1;
         request->num2= num2;
         return client_->async_send_request(request);

    }


private:
    rclcpp::Client<Addints>::SharedPtr client_;
    


};


int main(int argc, char  *argv[])
{
    if(argc != 3){
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"请输入两个整数");
        return 1;
    }

    rclcpp::init(argc,argv);
    auto client = std::make_shared<Client>();

    bool flig = client->service_connect();
    if(!flig){
        RCLCPP_INFO(rclcpp::get_logger("reclcpp"),"服务器连接失败，程序结束");
        return 0;
    }
    auto future = client->send_request(atoi(argv[1]),atoi(argv[2]));
    if(rclcpp::spin_until_future_complete(client,future)==rclcpp::FutureReturnCode::SUCCESS){
            RCLCPP_INFO(client->get_logger(),"响应成功 sum =%d",future.get()->sum);

    }
    else{
        RCLCPP_INFO(client->get_logger(),"响应失败");
    }


  

    rclcpp::shutdown();
    return 0;
}
