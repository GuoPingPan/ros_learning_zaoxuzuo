#include<ros/ros.h>
#include<turtlesim/Pose.h>
#include"tf2_ros/transform_broadcaster.h"


#include"geometry_msgs/TransformStamped.h"
#include"tf2_ros/buffer.h"
#include"tf2/LinearMath/Quaternion.h"

std::string chi_frame = "";

void cb(const turtlesim::Pose::ConstPtr &pose){

    static tf2_ros::TransformBroadcaster broadcaster;

    geometry_msgs::TransformStamped ts;

    ts.header.frame_id = "world";
    ts.header.stamp  = ros::Time::now();
    ts.child_frame_id = chi_frame;


    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0.0;

    tf2::Quaternion q;

    q.setRPY(0,0,pose->theta);

    ts.transform.rotation.w = q.getW();
    ts.transform.rotation.x = q.getX();
    ts.transform.rotation.y = q.getY();
    ts.transform.rotation.z = q.getZ();


    broadcaster.sendTransform(ts);



    return;
}



int main(int argc, char **argv){

    ros::init(argc, argv, "listen_to_turtle");

    ros::NodeHandle n;

    ros::param::param<std::string>("~child_frame_id", chi_frame, "turtle1");

    ROS_INFO("Frame %s", chi_frame.c_str());

    ros::Subscriber pose_sub = n.subscribe<turtlesim::Pose>(chi_frame+"/pose", 1000, cb);

    ros::spin();



    return 0;
}