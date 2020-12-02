#include "RobotPoint.hh"

//Point2D::Point2D (double x, double y)  {
//    this->x = x;
//    this->y = y;
//}

Point2D Point2D::operator+(const Point2D &b) const {
    Point2D a = *this;
    a.x = a.x + b.x;
    a.y = a.y + b.y;
    return a;
}

Point2D Point2D::operator-(const Point2D &b) const {
    Point2D a = *this;
    a.x = a.x - b.x;
    a.y = a.y - b.y;
    return a;
}

bool Point2D::operator==(const Point2D &b) const {
    return compareDouble(this->x, b.x) && compareDouble(this->y, b.y);
}

void Point2D::setval(double x, double y)  {
    this->x = x;
    this->y = y;
}

void Point2D::printval()  {
    std::cout << "x:" << this->x << " y:" << this->y << std::endl;
}

bool compareDouble(double a, double b)  {
    return std::abs(a-b) < EPSILON; //or fabs
}

bool bounding_box(double x1, double y1, double x2, double y2, double px, double py)  {
    double left, top, right, bottom;
//    x1 = std::abs(x1);
//    x2 = std::abs(x2);
//    y1 = std::abs(y1);
//    y2 = std::abs(y2);
//    px = std::abs(px);
//    py = std::abs(py);

    if(x1 < x2) {
        left = x1;
        right = x2;
    }
    else {
        left = x2;
        right = x1;
    }
    if(y1 < y2) {
        top = y1;
        bottom = y2;
    }
    else {
        top = y2;
        bottom = y1;
    }
//    std::cout << x1 << std::endl;
//    std::cout << y1 << std::endl;
//    std::cout << x2 << std::endl;
//    std::cout << y2 << std::endl;
//    std::cout << left << std::endl;
//    std::cout << right << std::endl;
//    std::cout << bottom << std::endl;
//    std::cout << top << std::endl;
//    std::cout << "----" << std::endl;
    if( (px+0.01) >= left && (px-0.01) <= right &&
            (py+0.01) >= top && (py-0.01) <= bottom )
        return true;
    else
        return false;
}

bool find_continuation(const Point2D &o1, const Point2D &p1, const Point2D &o2, const Point2D &p2, int path1, int path2)  {
    if(path1 == path2)  {
        return o1 == o2 || o1 == p2 || p1 == o2 || p1 == p2;
    }
    return false;
}

bool find_intersection(const Point2D &o1, const Point2D &p1, const Point2D &o2, const Point2D &p2, Point2D &px)  {
    Point2D x = o2 - o1;
    Point2D d1 = p1 - o1;
    Point2D d2 = p2 - o2;

    float cross = d1.x*d2.y - d1.y*d2.x;
    if (std::abs(cross) < EPSILON)
        return false;

    double t1 = (x.x * d2.y - x.y * d2.x)/cross;
    d1.x *= t1; d1.y *= t1;
    px = o1 + d1;// * t1;

    if(bounding_box(o1.x,o1.y,p1.x,p1.y,px.x,px.y) && bounding_box(o2.x,o2.y,p2.x,p2.y,px.x,px.y))
        return true;

     return false;
}

bool find_point_in_line(const Point2D &o, const Point2D &p, const Point2D &c, Point2D &r, double dist)  {
    if(c==o)
        return false;

    Point2D u = c-o;
    double uu = sqrt(u.x*u.x+u.y*u.y);

    r.x = o.x + u.x/uu * (uu-dist);
    r.y = o.y + u.y/uu * (uu-dist);
    if(bounding_box(o.x,o.y,p.x,p.y,r.x,r.y))
        return true;
    return false;
}
