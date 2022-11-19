#include<ros/ros.h>
#include<geometry_msgs/PoseStamped.h>
#include<turtlesim/Spawn.h>
#include<tf2_ros/transform_listener.h>
#include<geometry_msgs/Twist.h>


int main(int argc, char **argv){

    ros::init(argc, argv, "create_turtle");

    ros::NodeHandle n;

    turtlesim::Spawn spawn;
    spawn.request.name = "turtle2";
    spawn.request.theta = 1.57;
    spawn.request.x = 1.57;
    spawn.request.y = 1.57;

    ros::service::waitForService("/spawn");
    ros::service::call("/spawn", spawn);

    


    return 0;
}
