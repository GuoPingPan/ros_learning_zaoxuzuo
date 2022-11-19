#include<ros/ros.h>

int main(int argc,char **argv){

	ros::init(argc,argv,"helloworld");

	ros::NodeHandle n;

	ROS_INFO("HelloWorld!");


	return 0;
}
