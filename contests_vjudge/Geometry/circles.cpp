#include <iostream>
#include <cmath>
using namespace std;

struct C_Point
{
    double x;
    double y;
};


struct Circle
{
    C_Point c; // center
    double radius;
};


double cal_distance(C_Point p1, C_Point p2){
    double dis = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    return dis;
}



int main() {
    // user will input 4 end points, 2 for each circle
    C_Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cin >> p3.x >> p3.y >> p4.x >> p4.y;

    Circle c1;
    // calculate center of circle1 : (x1+x2)/2,  (y1+y2)/2
    c1.c.x = (p1.x + p2.x)/2.0;
    c1.c.y = (p1.y + p2.y)/2.0;
    // calculate radius of circle 1 
    c1.radius = (cal_distance(p1,p2)/2.0);  // cal diameter then divide by 2

    Circle c2;
    // calculate center of circle2 : (x1+x2)/2,  (y1+y2)/2
    c2.c.x = (p3.x+p4.x)/2.0;
    c2.c.y = (p3.y+p4.y)/2.0;
    c2.radius = (cal_distance(p3,p4)/2.0);  // cal diameter then divide by 2

    double c1c2 = cal_distance(c1.c, c2.c);  // calculate distance between 2 centers

    if (c1c2 > (c1.radius + c2.radius)){
        cout <<"NO";
    }
    else{
        cout << "YES";
    }

    return 0;
}