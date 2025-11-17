#include <iostream>
#include <cmath>
using namespace std;

struct C_Point  // New datatype for cartesian point
{
    double x;
    double y;
};

struct Line
{
    C_Point p1;
    C_Point p2;
};


double cal_slope(C_Point& p1, C_Point& p2, bool & is_vertical){
    if (fabs(p1.x - p2.x) < 1e-6){
        is_vertical = true; // indicate vertical
        return 0;
    }
    double slope = (p2.y - p1.y) / (p2.x - p1.x);
    return slope;
}
bool check_parallel(Line l1, Line l2){  // return true if the two lines are parallel
    bool is_vertical_line_1 = false;
    bool is_vertical_line_2 = false;
    double slope1 = cal_slope(l1.p1, l1.p2, is_vertical_line_1);
    double slope2 = cal_slope(l2.p1, l2.p2, is_vertical_line_2);
    
    
    if (is_vertical_line_1 && is_vertical_line_2){ // indicate that two line are vertical
        return true;
    }
    else if(is_vertical_line_1 != is_vertical_line_2){ // indicate that one line is vertical and the other is not > not parallel > return false
        return false;
    }

    if (fabs(slope1 - slope2) < 1e-6){ // indicate that two line have the same slope > parallel > return true
        return true;
    }
    return false;   // else > return false

}
int main() {
    C_Point p1, p2; // for first line
    C_Point p3, p4; // for second line
    
    cin >> p1.x >> p1.y >> p2.x >> p2.y;  // two points for first line
    cin >> p3.x >> p3.y >> p4.x >> p4.y;  // two points for second line

    Line line1;
    Line line2;
    line1.p1 = p1;
    line1.p2 = p2;

    line2.p1 = p3;
    line2.p2 = p4;



    if(check_parallel(line1, line2)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    
    return 0;
}