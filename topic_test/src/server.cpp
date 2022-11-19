#include<ros/ros.h>
#include"topic_test/AR.h"



bool doCaculate(topic_test::AR::Request& req, topic_test::AR::Response& res){

    res.reply = req.question + 10;
    ROS_INFO("Reply %f",res.reply);

    return true;
}


int main(int argc, char **argv){

    ros::init(argc, argv, "server");

    ros::NodeHandle n;

    ros::ServiceServer server = n.advertiseService("get_reply",doCaculate);

    ros::spin();



    return 0;
}