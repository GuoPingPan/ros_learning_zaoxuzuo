#include<ros/ros.h>
#include"geometry_msgs/PointStamped.h"
#include"geometry_msgs/TransformStamped.h"
#include"tf2_ros/buffer.h"
#include"tf2_ros/transform_listener.h"

// 在buffer的transform中有用到 
// namespace tf2
#include"tf2_geometry_msgs/tf2_geometry_msgs.h" 

int main(int argc, char **argv){

    ros::init(argc, argv , "listener");

    tf2_ros::Buffer buffer;

    tf2_ros::TransformListener listener(buffer);

    ros::Rate r(1);


    while (ros::ok())
    {
        geometry_msgs::PointStamped point_laser;
        point_laser.header.frame_id = "laser";
        point_laser.header.stamp = ros::Time::now();

        point_laser.point.x = 100;
        point_laser.point.y = 100;
        point_laser.point.z = 100;

        try{
            geometry_msgs::PointStamped point_base;
            point_base = buffer.transform(point_laser,"base_link",ros::Duration(10));
            ROS_INFO("x: %f, y: %f, z: %f",point_base.point.x, point_base.point.y, point_base.point.z);

        }
        catch(const std::exception& e){
            
            ROS_INFO("Error");

        }

        r.sleep();
        ros::spinOnce();
    }
    

    return 0;
}