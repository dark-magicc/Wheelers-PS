#include <iostream>
using namespace std;


// Structure representing a point in Cartesian coordinates
struct Point_Cartesian
{
    double x;
    double y;
};

// Structure representing a line defined by two Cartesian points
struct Line
{
    Point_Cartesian p1;
    Point_Cartesian p2;
};

// Function to calculate the slope of a line passing through two points
double cal_slope(Point_Cartesian p1, Point_Cartesian p2){
    double res = (p2.y - p1.y) / (p2.x - p1.x);
    return res;
}

// Function to check whether a given point (p3) lies on a line (l)
bool check_point(Line l, Point_Cartesian p3){
    // Calculate the slope between line endpoints (p1, p2)
    double slope1 = cal_slope(l.p1, l.p2);
    // Calculate the slope between one line endpoint (p1) and the point to test (p3)
    double slope2 = cal_slope(l.p1, p3);

    // If both slopes are equal, the point lies on the same line
    if (slope1 == slope2){
        return true;
    }
    else{
        return false;
    }

}

int main() {
    // Define a line using two points
    Line l;
    l.p1 = {2,3};
    l.p2 = {3,4};

    // Define a point to test
    Point_Cartesian p3 = {1,2};

    // Output: 1 (true) if it lies on the line, 0 (false) otherwise
    cout << check_point(l, p3);

    return 0;
}