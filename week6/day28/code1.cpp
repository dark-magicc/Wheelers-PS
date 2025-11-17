// converting points between Polar and Cartesian coordinate systems.

#include <iostream>
#include <cmath>
using namespace std;


// for mathematical functions like sin(), cos(), atan2(), sqrt()
const double PI = 3.14;

// ---------------------------
// ANGLE CONVERSION FUNCTIONS
// ---------------------------

// Function to convert degrees to radians
double d_to_r(double angle_in_degree){
    double angle_in_rad = angle_in_degree * PI /180;
    return angle_in_rad;
}
// Function to convert radians to degrees
double r_to_d (double angle_in_rad){
    double angle_in_degree = angle_in_rad * 180 /PI;
    return angle_in_degree;
}

// ---------------------------
// STRUCTURE DEFINITIONS
// ---------------------------

// Structure representing a point in Cartesian coordinates (x, y)
struct Point_Cartesian  // new datatype like int, float
{
    double x;
    double y;
};

// Structure representing a point in Polar coordinates (magnitude, angle)
struct Point_Polar // new datatype like int, float
{
    double mag;
    double angle;  // radian
};

// ---------------------------
// COORDINATE CONVERSION FUNCTIONS
// ---------------------------

// Convert a Polar point (r, θ) to Cartesian (x, y)
Point_Cartesian polar_to_cartesian(Point_Polar p){
    // Apply trigonometric formulas:
    // x = r * cos(θ)
    // y = r * sin(θ)
    double x = p.mag * cos(p.angle);
    double y = p.mag * sin(p.angle);

    return {x,y};
}

// Convert a Cartesian point (x, y) to Polar (r, θ)
Point_Polar cartesian_to_polar(Point_Cartesian p){
    double mag = sqrt((p.x * p.x) + (p.y*p.y));
    double angle = atan2(p.y, p.x);


    return {mag,angle};
}

int main() {
    Point_Polar p1;  // polar
    p1.mag = 5;
    p1.angle = d_to_r(53.1);

    Point_Cartesian p2;
    p2 = polar_to_cartesian (p1);  // take mag, angle >  x, y

    Point_Polar p3 = cartesian_to_polar(p2);
    cout << p3.mag << endl;
    cout << p3.angle << endl;

    return 0;
}