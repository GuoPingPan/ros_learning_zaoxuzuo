#include"ros/ros.h"
#include"actionlib/server/simple_action_server.h"
#include"learning_action/AddIntsAction.h"

typedef actionlib::SimpleActionServer<learning_action::AddIntsAction> Server;

void cb(const learning_action::AddIntsGoalConstPtr &goal, Server *server){


    int num = goal->num;

    int result = 0;

    learning_action::AddIntsFeedback feedback;

    ros::Rate r(10);
    for (size_t i = 0; i <= num; i++)
    {
        result += 1;
        feedback.feedback = i / double(num);
        server->publishFeedback(feedback);

        r.sleep();
    }

    learning_action::AddIntsResult ri;
    
    ri.result = result;
    
    server->setSucceeded(ri);


    return;
}

int main(int argc, char **argv){

    ros::init(argc, argv, "action_server");
    
    ros::NodeHandle n;

    Server server(n,"action_msg",boost::bind(&cb,_1,&server),false);

    server.start();

    ros::spin();

    return 0;
}