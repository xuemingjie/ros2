#include "rclcpp/rclcpp.hpp"
#include "xiaomi/xiaomi.h"
#include <serial/serial.h>




int main(int argc, char** argv)
{
    serial::Serial serialPort;
    rclcpp::init(argc,argv);
    
    xiaomi_set xiaomi_no1;
    xiaomi_set xiaomi_no2;

    initinalXiaomiSets(xiaomi_no1,1);//初始化NO.1
    
    initinalXiaomiSets(xiaomi_no2,2);


    try
    {
        serialPort.setPort("/dev/ttyUSB0");
        serialPort.setBaudrate(921600);
        serial::Timeout _time = serial::Timeout::simpleTimeout(1000);
        serialPort.setTimeout(_time);
        serialPort.open();
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"open port");
    }

    catch (serial::IOException &e)
    {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"),"Unable to open port");
        return -1;
    }



    
    serialPort.write(xiaomi_no1.At_mode.data);//AT模式
    serialPort.write(xiaomi_no1.zero.data); //设置零位
    serialPort.write(xiaomi_no2.zero.data);
    serialPort.write(xiaomi_no1.able.data);//1号使能
    serialPort.write(xiaomi_no2.able.data);//2号使能
    
    
    
    while (rclcpp::ok())
    {
        
    }
    
    


    serialPort.write(xiaomi_no1.terminal.data);
   
 
    serialPort.write(xiaomi_no2.terminal.data);

   

        
        

     serialPort.close();//关闭串口 
     


return 0;










    
}
