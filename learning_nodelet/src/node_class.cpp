#include"nodelet/nodelet.h"
#include"pluginlib/class_list_macros.hpp"
#include"ros/ros.h"
#include"std_msgs/Float64.h"

namespace nodelet_demo_ns{


    class Myplus: public nodelet::Nodelet {
    public:
        Myplus(){
            value = 10;
        }

        void onInit(){

            ros::NodeHandle& n = getPrivateNodeHandle();
            n.getParam("value", value);

            pub = n.advertise<std_msgs::Float64>("out", 100);
            sub = n.subscribe<std_msgs::Float64>("in", 100, &Myplus::doCb,this);


            
        }

         void doCb(const std_msgs::Float64::ConstPtr& p){
            double num = p->data;
            //数据处理
            double result = num + value;
            std_msgs::Float64 r;
            r.data = result;
            //发布
            pub.publish(r);
        }

    private:
        double value;

        ros::Publisher pub;
        ros::Subscriber sub;

    };

}


PLUGINLIB_EXPORT_CLASS(nodelet_demo_ns::Myplus, nodelet::Nodelet)

