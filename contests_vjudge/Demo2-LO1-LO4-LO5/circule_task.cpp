// Given center of a circle and its radius
// and given some other points
// check for all points if it is inside or outside the circle
// idea: calculate distance between center and point
// if that distance > radius, then the point is outside the circle
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
    Circle c1;
    cin >> c1.c.x >> c1.c.y >> c1.radius;
    int no_of_test_points;
    cin >> no_of_test_points;

    for (int i = 0; i < no_of_test_points; i++)
    {
        C_Point p;
        cin >> p.x>> p.y;
        if (cal_distance(c1.c, p) <= c1.radius){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        if (i != no_of_test_points-1){
            cout << endl;
        }
    }
    
    
    return 0;
}