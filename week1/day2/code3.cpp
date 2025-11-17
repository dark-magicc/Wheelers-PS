// Write a C++ function that takes three sides of a triangle and calculates its area

// will use the rule  area = sqrt(s(s-a)(s-b)(s-c))

#include <iostream>
#include <cmath> // need to use sqrt
using namespace std;

void cal_triangle_area(int a, int b, int c){
    double s = (a+b+c)/2.0;
    double area = sqrt(s*(s-a)*(s-b)*(s-c));
    cout << area;
    return;
}

int main() {
    int a,b,c;
    cin >> a >> b >>c;

    cal_triangle_area(a,b,c);
    
    return 0;
}