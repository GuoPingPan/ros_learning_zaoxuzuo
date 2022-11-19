#include<ros/ros.h>
#include"topic_test/AR.h"






int main(int argc, char **argv){

    ros::init(argc, argv, "client");

    ros::NodeHandle n;

    ros::ServiceClient client = n.serviceClient<topic_test::AR>("get_reply");

    // ros::service::waitForService("get_reply");

    client.waitForExistence();

    topic_test::AR msg;
    msg.request.question = 100;

    bool flag = client.call(msg);

    if(flag){
        ROS_INFO("reply %f",msg.response.reply);
    }
    else{
        ROS_INFO("Call Error");
    }
 



    return 0;
}