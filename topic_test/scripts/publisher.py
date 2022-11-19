#! /usr/bin/env python
# _*_ coding: utf-8 _*_
"""
    需求: 实现基本的话题通信，一方发布数据，一方接收数据，
         实现的关键点:
         1.发送方
         2.接收方
         3.数据(此处为普通文本)

         PS: 二者需要设置相同的话题


    消息发布方:
        循环发布信息:HelloWorld 后缀数字编号

    实现流程:
        1.导包 
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 发布者 对象
        4.组织被发布的数据，并编写逻辑发布数据


"""
#1.导包 
import rospy
from std_msgs.msg import String,Header
from topic_test.msg import Random

if __name__ == "__main__":
    #2.初始化 ROS 节点:命名(唯一)
    rospy.init_node("talker_p")
    #3.实例化 发布者 对象
    pub = rospy.Publisher("chatter",String,queue_size=10)
    pub2 = rospy.Publisher("random_msgs",Random,queue_size=10)
    #4.组织被发布的数据，并编写逻辑发布数据
    msg = String()  #创建 msg 对象
    msg_front = "hello 你好"
    count = 0  #计数器 
    # 设置循环频率
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():

        #拼接字符串
        msg.data = msg_front + str(count)
        random_msgs = Random()

        pub.publish(msg)

        for i in range(100):
            random_msgs.data.append(i)
            random_msgs.num_3.append(i)

        random_msgs.size = 100
        random_msgs.name = 'faf'
        header = Header()
        random_msgs.multi_header.append(header)
        random_msgs.date = rospy.Time.now()

        pub2.publish(random_msgs)
        

        rate.sleep()
        rospy.loginfo("写出的数据:%s",msg.data)
        count += 1
