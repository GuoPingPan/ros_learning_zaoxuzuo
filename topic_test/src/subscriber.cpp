#include<ros/ros.h>
#include<std_msgs/String.h>
#include<sstream>

void callback(const std_msgs::String::ConstPtr& msg){

    ROS_INFO("The message receive: %s", msg->data.c_str());
}


int main(int argc,char **argv){

    ros::init(argc, argv, "subsciber");

    ros::NodeHandle n;

    ros::Subscriber subsciber;
    subsciber = n.subscribe<std_msgs::String>("topic_test", 10, callback);
    
    
    ros::spin();    


    return 0;
}