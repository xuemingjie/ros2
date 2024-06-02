/*
  问题： Time 与 Duration有什么区别
  答：
      1.二者只是API使用类似；
      2.二者有着本质区别
         rclcpp::Time t2(2,500000000L) ----指的是一个具体时刻 1970.1.1 08::00::02::500
         rclcpp::Duration du2(2,500000000L); ---指的是一个时间段，持续2.5s





*/
//1.包含头文件
#include "rclcpp/rclcpp.hpp"
using namespace std::chrono_literals;
//  3.自定义节点类;
class MyNode: public rclcpp::Node{
public:
  MyNode():Node("time_node_cpp"){
   // demo_rate();
   // demo_time();
   //demo_duration();
   demo_opt();

}
private:
 //演示Rate的使用
    void demo_rate(){
      //1.创建 Rate对象
      rclcpp::Rate rate1(500ms);//设置休眠时间0.5s
      rclcpp::Rate rate2(1.0);//设置执行频率1hz
      //2.调用Rate的sleep函数
      while (rclcpp::ok())
      {
        RCLCPP_INFO(this->get_logger(),"------------------");
        //rate1.sleep();
        rate2.sleep();
      }
      

    }
    //演示Time的使用
    void demo_time(){
      //1.创建Time对象
      rclcpp::Time t1(500000000L);//5*10^8ns = 0.5s
      rclcpp::Time t2(2,500000000L);//2.5s
      //当前时间 两种，选第二种简单的
      //rclcpp::Time right_now = this -> get_clock()->now();
      rclcpp::Time right_now = this -> now();
      //2.调用Time对象的函数
      RCLCPP_INFO(this->get_logger(),"s = %.2f, ns = %ld",t1.seconds(),t1.nanoseconds());
      RCLCPP_INFO(this->get_logger(),"s = %.2f, ns = %ld",t2.seconds(),t2.nanoseconds());
      RCLCPP_INFO(this->get_logger(),"s = %.2f, ns = %ld",right_now.seconds(),right_now.nanoseconds());


    }
    //演示Duration 的使用
    void demo_duration(){
      //1.创建Duration对象
      rclcpp::Duration du1(1s);
      rclcpp::Duration du2(2,500000000L);
      //2.调用函数
      RCLCPP_INFO(this->get_logger(),"s = %.2f, ns = %ld",du1.seconds(),du1.nanoseconds());
      RCLCPP_INFO(this->get_logger(),"s = %.2f, ns = %ld",du2.seconds(),du2.nanoseconds());
      


    }
    //演示运算符的使用
    void demo_opt(){
        rclcpp::Time t1(10,0);
        rclcpp::Time t2(30,0);

        rclcpp::Duration du1(8,0);
        rclcpp::Duration du2(17,0);

        //运算
        //比较运算符
        RCLCPP_INFO(this->get_logger(),"t1 >=  t2? %d",t1 >= t2);
        RCLCPP_INFO(this->get_logger(),"t1 <  t2? %d",t1 < t2);
        //数学运算
        rclcpp::Duration du3 =  t2 - t1;
        rclcpp::Time t3 = t1 + du1;
        rclcpp::Time t4 = t1 - du1;
        
        RCLCPP_INFO(this->get_logger(),"du3 = %.2f",du3.seconds());//20
        RCLCPP_INFO(this->get_logger(),"t3 = %.2f",t3.seconds());//18
        RCLCPP_INFO(this->get_logger(),"t4 = %.2f",t4.seconds());//2
        RCLCPP_INFO(this->get_logger(),"-------------------");
        
        RCLCPP_INFO(this->get_logger(),"du1 >= du2? %d",du1 >= du2);
        RCLCPP_INFO(this->get_logger(),"du1 < du2? %d",du1 < du2);
        rclcpp::Duration du4 = du1 * 3;
        rclcpp::Duration du5 = du1 + du2;
        rclcpp::Duration du6 = du1 - du2;
        RCLCPP_INFO(this->get_logger(),"du4 =  %.2f",du4.seconds());//24
        RCLCPP_INFO(this->get_logger(),"du5 =  %.2f",du5.seconds());//25
        RCLCPP_INFO(this->get_logger(),"du6 =  %.2f",du6.seconds());//-9





    }
};
int main(int argc, char ** argv)
{
//2.初始化ros2客户端;
rclcpp::init(argc,argv);
//4.调用spin函数，传入自定义类对象指针;
rclcpp::spin(std::make_shared<MyNode>());
//5.释放资源;
rclcpp::shutdown();
return 0;
}