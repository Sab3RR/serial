#include <ros/ros.h>
#include <std_msgs/String.h>
//#include <visualization_msgs/Marker.h>


//#include <sstream>
//#include <iostream>
//#include <fstream>
//#include <vector>
#include <map>
//#include <cmath>
#include <fcntl.h>
//#include <sys\types.h>
//#include <sys\stat.h>
//#include <io.h>

int main(int ac, char** ar)
{
    ros::init(ac, ar, "points_and_lines");
    ros::NodeHandle n;
   // ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 10);
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("imu", 10);
    ros::Rate r(10);

    std::string port = "/dev/ttyACM0";
    int device;
    device = open(port.c_str(), O_RDWR );

    while(ros::ok())
    {
        std::string response;
        char buffer[1];

        while(true)
        {
            int n = read(device, buffer, sizeof buffer);
            if (n != 0)
            {
                if (buffer[0] != '\n')
                    response += std::string(buffer);
                else
                {
                    std_msgs::String msg;



                    msg.data = response;
                    chatter_pub.publish(msg);
                    //ROS_INFO("%s", response.c_str());
                    break;
                }
            }

        }

        //ROS_INFO("%s", buffer);
        //r.sleep();
    }

}
