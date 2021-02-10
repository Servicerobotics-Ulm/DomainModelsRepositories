#ifndef ROBOTPOINT_H
#define ROBOTPOINT_H
#include <iostream>
#include <utility>
#include <cmath>
#include <set>

typedef enum { NORMAL, CROSS, WAIT, NEWCROSS } node_type;
typedef enum { NORMAL_EDGE, DELETE_EDGE } edge_type;
typedef enum { OCCUPIED, AVAILABLE, OK } node_status;
typedef enum { ZERO_WAY, ONE_WAY, TWO_WAY , ONE_WAY_EXPRESS} edge_dir;
static const double EPSILON = 1e-6; //7 is okay also, somehow epsilon from compiler is not enough
//std::numeric_limits<double>::epsilon();#include <limits>

struct graphNode {
    int id;
    double x;
    double y;
    int pose;
    int path;
    double width;
    node_type type;
    node_status sts;
    std::string robotID;
};

class RobotPoint  {
public:
    double x;
    double y;
    int pose;
    int path;
    double width;
    node_type type ;
    std::set<int> intersec_path;
    friend std::ostream& operator<< (std::ostream& stream, const RobotPoint& robotPoint){
    	stream<<"x: "<<robotPoint.x<<" y: "<<robotPoint.y<<" pose: "<<robotPoint.pose<<" path: "<<robotPoint.path;
    	if(robotPoint.type == CROSS){
    		stream<<" type: cross";
    	}else if(robotPoint.type == NEWCROSS){
    		stream<<" type: newcross";
    	}else if(robotPoint.type == NORMAL){
    		stream<<" type: normal";
    	}else if(robotPoint.type == WAIT){
    		stream<<" type: wait";
    	}
//    	stream<<"intersec_path: ";
//    	for(std::set<int>::iterator iter = robotPoint.intersec_path.begin(); iter!=robotPoint.intersec_path.end();++iter){
//    		stream<<*iter<<" ";
//    	}
    	return stream;
    }
};

class RobotEdge  {
public:
    int path;
    int way;        //direction ?
    edge_type type;
    double gap;     //distance between point

    friend std::ostream& operator<< (std::ostream& stream, const RobotEdge& robotEdge){
    	stream<<"Path: "<<robotEdge.path<<" Way:"<<robotEdge.way<<" EdgeTye: "<<robotEdge.type<<" Gap: "<<robotEdge.gap;
    	return stream;
    }
};

class Point2D  {
public:
    double x;
    double y;
//    Point2D(double,double);
    Point2D operator+(const Point2D &b)const;
    Point2D operator-(const Point2D &b)const;
    bool operator==(const Point2D &b)const;
    void setval(double,double);
    void printval();
};

bool compareDouble(double a, double b);
bool find_continuation(const Point2D &o1, const Point2D &p1, const Point2D &o2, const Point2D &p2, int path1, int path2);
bool find_intersection(const Point2D&,const Point2D&,const Point2D&,const Point2D&,Point2D&);
bool find_point_in_line(const Point2D &o, const Point2D &p, const Point2D &c, Point2D &r, double dist);

#endif // ROBOTPOINT_H
