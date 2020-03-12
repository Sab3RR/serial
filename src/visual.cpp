#include <ros/ros.h>
#include <std_msgs/String.h>
#include <visualization_msgs/Marker.h>
#include "json.hpp"

#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>



int main()
{
    ros::init(ac, ar, "points_and_lines");
    ros::NodeHandle n;
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 10);
    ros::Subscriber sub = n.subscribe("imu", 10, chatterCallback);
}
