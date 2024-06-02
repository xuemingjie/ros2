#include "rclcpp/rclcpp.hpp"
#include "base_interfaces_demo/srv/addints.hpp"
using base_interfaces_demo::srv::Addints;
using namespace std::placeholders;

class Xue_Serve: public rclcpp::Node
{

    public:
        Xue_Serve():Node("ser")
        {
            RCLCPP_INFO(this->get_logger(),"服务端节点创建");

            server_=this->create_service<Addints>("addints",std::bind(&Xue_Serve::ser_cb,this,_1,_2));
        }
    private:
        void ser_cb(const Addints::Request::SharedPtr req,const Addints::Response::SharedPtr res)
        {
            res->sum = req->num1 + req->num2;
            RCLCPP_INFO(this->get_logger(),"%d = %d + %d",res->sum,req->num1,req->num2);
        }
        rclcpp::Service<Addints>::SharedPtr server_;
};



int main(int argc, char  *argv[])
{

    rclcpp::init(argc,argv);

    rclcpp::spin(std::make_shared<Xue_Serve>());


    rclcpp::shutdown();



    
    return 0;
}
