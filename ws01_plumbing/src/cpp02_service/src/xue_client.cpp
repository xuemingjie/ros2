#include "rclcpp/rclcpp.hpp"
#include "base_interfaces_demo/srv/addints.hpp"
using base_interfaces_demo::srv::Addints;

using namespace std::chrono_literals;
class Xue_Client: public rclcpp::Node
{

    public:
        Xue_Client(): Node("cli")
        {
            RCLCPP_INFO(this->get_logger(),"客户端节点建立");

            client_ = this->create_client<Addints>("addints");
        }

        bool connect_server()
        {
            while (!client_->wait_for_service(1s))
            {
                
                if(!rclcpp::ok())
                {
                   RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"手动终止函数");
                    return false;
                }
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"等待服务器连接中");
            }
            return true;


        }
        rclcpp::Client<Addints>::FutureAndRequestId sed_request(int num1,int num2)
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
    
    if (argc != 3)
    {
       RCLCPP_ERROR(rclcpp::get_logger("rclcpp"),"应该输入两个整数，程序退出");
       return 1;
    }
    

    rclcpp::init(argc,argv);
    

    auto client = std::make_shared<Xue_Client>();
    bool flag =client->connect_server();
    if(!flag)
    {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"),"服务器连接失败，程序退出");
        return 0;
    }
    auto future = client->sed_request(atoi(argv[1]),atoi(argv[2]));
    if(rclcpp::spin_until_future_complete(client,future) == rclcpp::FutureReturnCode::SUCCESS)
    {
        RCLCPP_INFO(client->get_logger(),"响应成功！ sum =%d",future.get()->sum);
    }

    else
    {
        RCLCPP_INFO(client->get_logger(),"响应失败");
    }



    rclcpp::shutdown();






    return 0;
}
