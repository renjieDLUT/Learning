#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include "opendrive/OpenDrive.hpp"
#include "commonroad/CommonRoad.hpp"
#include "opendrive_lane.cpp"
#include <cmath>
#include <vector>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "visualize_lanes");
  ros::NodeHandle n;
  ros::Publisher marker_pub = n.advertise<visualization_msgs::MarkerArray>("lane_marker_array", 10);
  // currently publishes every 10 seconds
  ros::Rate r(0.1);
  ros::NodeHandle nh;

  // get parameters from params.yaml
  std::string pathOD;
  nh.getParam("/pathToOpenDrive", pathOD);

  // create opendrive data structure and load info from OpenDrive File
  opendrive::OpenDriveData odr;
  bool bSuccess = opendrive::Load(pathOD, odr);

  // check if the file was loaded successfully
  if (!bSuccess)
  {
    ROS_FATAL("Unable to load Map file!");
    exit(0);
  }

  // marker arry to store all individual line strips
  visualization_msgs::MarkerArray line_strips;

  while (ros::ok())
  {
    int i = 0;
    visualization_msgs::Marker lineStripMain;
    lineStripMain.header.frame_id = "map";
    lineStripMain.header.stamp = ros::Time::now();
    lineStripMain.ns = "opendrive_visualize";
    lineStripMain.action = visualization_msgs::Marker::ADD;
    lineStripMain.pose.orientation.w = 1.0;
    lineStripMain.id = i;
    lineStripMain.type = visualization_msgs::Marker::LINE_STRIP;
    lineStripMain.color.a = 1.0;
    lineStripMain.color.r = 1.0;
    lineStripMain.scale.x = 0.12;

    for (opendrive::RoadInformation &road : odr.roads)
    {

      for (std::unique_ptr<opendrive::GeometryAttributes> &geometry : road.geometry_attributes)
      {
        lineStripMain.id = ++i;
        lineStripMain.points.clear();
        if (geometry->type == opendrive::GeometryType::LINE)
        {

          geometry_msgs::Point p;
          p.z = 0;
          p.x = geometry->start_position_x;
          p.y = geometry->start_position_y;
          lineStripMain.points.push_back(p);
          p.x = geometry->start_position_x + cos(geometry->heading) * geometry->length;
          p.y = geometry->start_position_y + sin(geometry->heading) * geometry->length;
          lineStripMain.points.push_back(p);
          lineStripMain.color.g = 0.0;
          lineStripMain.color.b = 0.0;
          line_strips.markers.push_back(lineStripMain);

          vector<SPoint> refencePoints;
          SPoint refencePoint;
          float step = 0;
          while (step < geometry->length)
          {
            refencePoint.s = step;
            refencePoint.heading = geometry->heading;
            refencePoint.point.x = geometry->start_position_x + cos(geometry->heading) * step;
            refencePoint.point.y = geometry->start_position_y + sin(geometry->heading) * step;
            refencePoints.push_back(refencePoint);
            step += 1;
          }
          try
          {
            vector<vector<geometry_msgs::Point>> lanePoints = discreteLanes(refencePoints, road);
            for (auto points : lanePoints)
            {
              lineStripMain.points.clear();
              lineStripMain.points = points;
              lineStripMain.id = ++i;
              lineStripMain.color.g = 1.0;
              lineStripMain.color.b = 1.0;
              line_strips.markers.push_back(lineStripMain);
            }
          }
          catch (std::length_error e)
          {
            std::cout << e.what() << std::endl;
          }
        }
        if (geometry->type == opendrive::GeometryType::ARC)
        {
          lineStripMain.id = i;
          i++;
          geometry_msgs::Point p;
          p.z = 0;
          p.x = geometry->start_position_x;
          p.y = geometry->start_position_y;
          lineStripMain.points.push_back(p);
          float s = 0, step = 0.2;
          while (s < (geometry->length))
          {
            float angle = geometry->heading + ((opendrive::GeometryAttributesArc *)(geometry.get()))->curvature * s;
            p.x = p.x + cos(angle) * step;
            p.y = p.y + sin(angle) * step;
            s += step;
            lineStripMain.points.push_back(p);
          }
          line_strips.markers.push_back(lineStripMain);
        }
        if (geometry->type != opendrive::GeometryType::ARC && geometry->type != opendrive::GeometryType::LINE)
        {
          std::cout << "other type:" << int(geometry->type) << std::endl;
        }
      }
    }

    marker_pub.publish(line_strips);
    line_strips.markers.clear();
    r.sleep();
  }
}