#include<ros/ros.h>

int main(int argc, char **argv){

    // setlocale(LC_ALL, ""); 只是为了输出中文
    ros::init(argc, argv, "test_vs");
    
    ROS_INFO("TEST 中文！");

    return 0;
}