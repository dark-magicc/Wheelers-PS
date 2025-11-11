// Idea: check if it is a triangle using triangle inequality theorem
// if triangle calculate its area
#include <iostream>
#include <cmath> // to use sqrt
#include <iomanip> // for setprecision
using namespace std;

// function to calculate area of triangle using lengths of 3 sides
double calc_area(int a, int b, int c){
    double s = (a+b+c)/2.0;
    double area = sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}

int main() {
    int a, b, c;
    cin >> a >>b >> c;

    if (a+b > c && a+c > b && b+c>a)
    {
        cout << "Valid" << endl;
        cout << fixed << setprecision(6)  << calc_area(a,b,c);
    }
    else{
        cout << "Invalid";
    }
    return 0;
}