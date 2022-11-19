#! /usr/bin/env python
# _*_ coding: utf-8 _*_

import rospy


if __name__ == "__main__":
    rospy.init_node("HelloVS")
    rospy.loginfo("Hello 中文")