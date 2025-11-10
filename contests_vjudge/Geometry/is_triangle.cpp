#include <iostream>
#include <cmath> // for sqrt
#include <iomanip> // for setprecision
using namespace std;

bool is_triangle(int a, int b, int c){
    if ( a +b > c && a+c > b && b+c > a){  // rule: any two sides of a triangle must be bigger than the third side
        return true;
    }
    return false;
}

double calc_area(int a, int b, int c){
    double s = (a+b+c) / 2.0;  // half of circumference
    double area = sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}

int main() {
    // Note: Input will be the distances of three lines not points

    int a, b, c;
    cin >> a >> b >> c;

    if (is_triangle(a,b,c)){ // function will take lengths of three lines and return true if those lines can make a trainlge
        cout << "Valid" << endl;
        cout << fixed << setprecision(6)  <<calc_area(a,b,c); // function
    }
    else{
        cout << "Invalid";
    }


    return 0;
}