#include<ros/ros.h>
#include"geometry_msgs/TransformStamped.h"
#include"tf2_ros/static_transform_broadcaster.h"
#include"tf2/LinearMath/Quaternion.h"
#include"tf2_ros/transform_broadcaster.h"


int main(int argc, char **argv){

    ros::init(argc, argv, "static_broadcaster");

    tf2_ros::StaticTransformBroadcaster broadcaster;
    tf2_ros::TransformBroadcaster broadcaster_nonstatic;

    geometry_msgs::TransformStamped ts;

    ts.header.stamp = ros::Time::now();
    ts.header.frame_id = "base_link";
    ts.header.seq = 100;

    ts.child_frame_id = "laser";

    ts.transform.translation.x = 100;
    ts.transform.translation.y = 100;
    ts.transform.translation.z = 100;


    tf2::Quaternion q;
    q.setRPY(1.57,0,0);
    
    ts.transform.rotation.w = q.getW();
    ts.transform.rotation.x = q.getX();
    ts.transform.rotation.y = q.getY();
    ts.transform.rotation.z = q.getZ();

    // 静态，只发送一次就能够保留很久
    broadcaster.sendTransform(ts);

    // geometry_msgs::TransformStamped ts_2;

    // ts_2 = ts;
    // ts_2.header.frame_id = "fa";
    // ts_2.child_frame_id = "r";
    // while(ros::ok()){

    //     // 循环发送
    //     broadcaster_nonstatic.sendTransform(ts_2);

    // }

    ros::spin();

    return 0;
}