#include"ros/ros.h"
#include"actionlib/client/simple_action_client.h"
#include"learning_action/AddIntsAction.h"

typedef actionlib::SimpleActionClient<learning_action::AddIntsAction> Client;

void done_cb(const actionlib::SimpleClientGoalState &state, const learning_action::AddIntsResultConstPtr &result)
{
    if(state.state_ == state.SUCCEEDED){
        ROS_INFO("Result: %f",result->result);
    }
    else{
        ROS_INFO("Fail!");
    }
}

void active_cb(){
    ROS_INFO("active_server");
}

void feedback_cb(const learning_action::AddIntsFeedbackConstPtr &feedback){

    ROS_INFO("Feedback: %f",feedback->feedback);

}


int main(int argc, char **argv){

    ros::init(argc, argv, "action_client");
    
    ros::NodeHandle n;

    Client client(n,"action_msg",true);

    client.waitForServer();


    learning_action::AddIntsGoal goal;

    goal.num = 10;

    client.sendGoal(goal, &done_cb, &active_cb, &feedback_cb);

    
    ros::spin(); //必须



    return 0;
}