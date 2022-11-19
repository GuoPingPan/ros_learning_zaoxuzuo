#! /usr/bin/env python
# _*_ coding: utf-8 _*_

import rospy

if __name__=="__main__":
    rospy.init_node("non_build")
    rospy.loginfo("no need to build")
    rospy.loginfo("全是中文")