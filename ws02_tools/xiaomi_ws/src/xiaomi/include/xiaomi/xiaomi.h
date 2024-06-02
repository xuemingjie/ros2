#ifndef _XIAOMI_H_
#define _XIAOMI_H_
#include "std_msgs/msg/u_int8_multi_array.hpp"


struct xiaomi_set{

std_msgs::msg::UInt8MultiArray At_mode;
std_msgs::msg::UInt8MultiArray mode_set_0;
std_msgs::msg::UInt8MultiArray  mode_set_1;
std_msgs::msg::UInt8MultiArray mode_set_2;
std_msgs::msg::UInt8MultiArray mode_set_3;
std_msgs::msg::UInt8MultiArray zero;
std_msgs::msg::UInt8MultiArray able;
std_msgs::msg::UInt8MultiArray terminal;


};
void initinalXiaomiSets (xiaomi_set& xiaomi_no,int);


union FloatConverter {
    float floatValue;
    uint8_t byteValue[sizeof(float)];
}  ;

std_msgs::msg::UInt8MultiArray convertFloatToHexVector(float arguments);

std_msgs::msg::UInt8MultiArray operator+(const std_msgs::msg::UInt8MultiArray &a, const std_msgs::msg::UInt8MultiArray &b);
void  mode_set(int id,float loc_ref,float limit_sqd, float limit_cur ,std_msgs::msg::UInt8MultiArray &loc_ref_set,std_msgs::msg::UInt8MultiArray &limit_sqd_set,std_msgs::msg::UInt8MultiArray &limit_cur_set);//位置模式参数设置函数

void  mode_set(int id,float sqd_ref, float limit_cur ,std_msgs::msg::UInt8MultiArray &sqd_ref_set,std_msgs::msg::UInt8MultiArray &limit_cur_set);//速度模式参数设置函数

//void  mode_set(int id,float iq_ref,std_msgs::msg::UInt8MultiArray &iq_ref_set);//电流模式参数设置函数
// void  mode_set(int id,std_msgs::msg::UInt8MultiArray &sqd_ref_set,std_msgs::msg::UInt8MultiArray &limit_cur_set);

#endif