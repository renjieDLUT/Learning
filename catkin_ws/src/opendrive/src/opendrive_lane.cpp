#include <visualization_msgs/MarkerArray.h>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
#define SGN(x) x > 0 ? 1 : -1
struct WidthID
{
    int id;
    opendrive::LaneWidth width;
    bool operator<(const WidthID &rhs) const
    {

        return abs(id) < abs(rhs.id);
    }
};

struct SPoint
{
    float s;
    float heading;
    geometry_msgs::Point point;
};

vector<vector<geometry_msgs::Point>>
discreteLane(vector<SPoint> sPoints, set<WidthID> &widthIDs)
{
    vector<vector<geometry_msgs::Point>> res;

    for (auto widthID : widthIDs)
    {
        vector<geometry_msgs::Point> tmp;
        for (auto sPoint : sPoints)
        {
            float d = widthID.width.a;
            geometry_msgs::Point p;
            p.x = sPoint.point.x + cos(sPoint.heading + SGN(widthID.id) * M_PI / 2) * d;

            p.y = sPoint.point.y + sin(sPoint.heading + SGN(widthID.id) * M_PI / 2) * d;
            sPoint.point = p;
            tmp.push_back(p);
        }
        res.push_back(tmp);
    }
    return res;
}

vector<set<WidthID>> calcWidthID(opendrive::RoadInformation &road)
{
    vector<set<WidthID>> res;
    if (road.lanes.lane_sections.size() == 0)
        return res;
    // for (opendrive::LaneSection &lane_section : road.lanes.lane_sections)
    {
        std::set<WidthID> halfRight, halfLeft;
        for (const opendrive::LaneInfo &right : road.lanes.lane_sections[0].right)
        {
            WidthID tmp;
            tmp.id = right.attributes.id;
            tmp.width = right.lane_width[0];
            halfRight.insert(tmp);
        }
        for (const opendrive::LaneInfo &left : road.lanes.lane_sections[0].left)
        {
            WidthID tmp;
            tmp.id = left.attributes.id;
            tmp.width = left.lane_width[0];
            halfLeft.insert(tmp);
        }
        res.push_back(halfRight);
        res.push_back(halfLeft);
    }
    return res;
}

vector<vector<geometry_msgs::Point>> discreteLanes(vector<SPoint> sPoints, opendrive::RoadInformation &road)
{
    vector<vector<geometry_msgs::Point>> res;

    try
    {
        vector<set<WidthID>> widths = calcWidthID(road);
        for (auto tmp : widths)
        {
            vector<vector<geometry_msgs::Point>> half = discreteLane(sPoints, tmp);
            res.insert(res.end(), half.begin(), half.end() - 1);
        }
    }
    catch (std::length_error e)
    {
        std::cout << e.what() << std::endl;
        return res;
    }

    return res;
}