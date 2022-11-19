#include<ros/ros.h>
#include<geometry_msgs/PoseStamped.h>
#include<turtlesim/Spawn.h>
#include<tf2_ros/transform_listener.h>
#include<geometry_msgs/Twist.h>


int main(int argc, char **argv){

    ros::init(argc, argv, "follow_turtle");

    ros::NodeHandle n;

    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 1000);

    ros::Rate r(10);

    while (ros::ok())
    {
        /* code */
        // 用ros::Time::now有很大延迟
        try
        {
            /* code */
                    
            // turtle1在turtle2下的表达
            if(buffer.canTransform("turtle2", "turtle1", ros::Time(0))){
                geometry_msgs::TransformStamped ts = buffer.lookupTransform("turtle2", "turtle1", ros::Time(0));
                ROS_INFO("Can Transform");

                std::cout << ts.transform.translation  << std::endl;

                geometry_msgs::Twist twist;
                twist.linear.x =  0.5*sqrt(pow(ts.transform.translation.x,2) + pow(ts.transform.translation.y,2));
                twist.angular.z = 5 * atan2(ts.transform.translation.y,   ts.transform.translation.x);
                pub.publish(twist);
            }
            // geometry_msgs::TransformStamped ts_w = buffer.lookupTransform("laser", "base_link", ros::Time(0));

            // std::cout << ts_w.header.frame_id << " " << ts_w.transform.translation << std::endl;


        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        r.sleep();

        ros::spinOnce();

    }
    



    return 0;
}


