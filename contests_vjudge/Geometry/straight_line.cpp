#include <iostream>
#include <cmath> // for fabs
using namespace std;

struct C_Point  // New datatype for cartesian point
{
    double x;
    double y;
};

double cal_distance(C_Point p1, C_Point p2){
    double dis = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    return dis;
}


bool check_straight_line(C_Point p1, C_Point p2, C_Point p3){  // will return true if the points are at the same straight line
    double x = cal_distance(p1, p2);
    double y = cal_distance(p1, p3);
    double z = cal_distance(p3, p2);

    double max_side_length = max({x,y,z});
    double other_sides_length = x + y + z - max_side_length;
    
    if (fabs(max_side_length - other_sides_length) < 1e-6){  // check if max_side == other_sides (note: 1e-6 is floating-point comparisons)
                                                            // (using 1e-6 as epsilon to handle floating-point precision errors)
        return true;
    }
    return false;
}   

int main() {
    // Input will be three points in cartesian
    C_Point p1;
    C_Point p2;
    C_Point p3;

    cin >> p1.x >> p1.y; // user will input first point (x,y)
    cin >> p2.x >> p2.y; // user will input second point (x,y)
    cin >> p3.x >> p3.y; // user will input third point (x,y)

    if (check_straight_line(p1,p2,p3)){
        cout << "YES";
    }
    else{
        cout <<"NO";
    }

    return 0;
}