#include "rclcpp/rclcpp.hpp"
#include "base_interfaces_demo/srv/addints.hpp"

using base_interfaces_demo::srv::Addints;
using std::placeholders::_1;
using std::placeholders::_2;

class Server : public rclcpp::Node{

public:
        Server() : Node("server_node"){
            RCLCPP_INFO(this->get_logger(),"服务器节点建立");

           server_= this->create_service<Addints>("lianxi",std::bind(&Server::ser_cb,this,_1,_2));

        }
private:
        rclcpp::Service<Addints>::SharedPtr server_;
        void ser_cb(const Addints::Request::SharedPtr req,const Addints::Response::SharedPtr res){
            res->sum = req->num1 + req->num2;
            RCLCPP_INFO(this->get_logger(),"%d + %d = %d",req->num1,req->num2,res->sum);
            
        }



};




int main(int argc, char  *argv[])
{
    rclcpp::init(argc,argv);


    auto Node = std::make_shared<Server>();
    rclcpp::spin(Node);



    rclcpp::shutdown();


    return 0;
}
