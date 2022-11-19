#include<ros/ros.h>
#include<std_msgs/String.h>
#include<sstream>
#include"topic_test/Random.h"

int main(int argc,char **argv){

    ros::init(argc, argv, "publisher");

    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<std_msgs::String>("topic_test",10);
    ros::Publisher pub2 = n.advertise<std_msgs::String>("topic_test",10);

    ros::Rate r(10);

    int count = 0;


    while (ros::ok())
    {
        std_msgs::String msg;
        
        std::stringstream ss;
        ss << "Pub" << count;

        msg.data = ss.str();

        pub.publish(msg);
        ROS_INFO("Pub");

        count++;

        r.sleep();

        topic_test::Random ran;

        for (size_t i = 0; i < 101; i++)
        {
            ran.data.push_back(20);
            ran.num_3[0] = 10;
            ran.num_3[1] = 10;
            ran.num_3[2] = 10;
            // ran.num_3[4] = 10;
            /* code */
        }
        ran.date = ros::Time::now();
        ran.size = 100;

        pub2.publish(ran);

        ros::spinOnce();
    }
    


    return 0;
}