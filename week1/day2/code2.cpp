// Write a program to print the circumference and area of a circle of radius entered by user by defining your own function.

#include <iostream>
using namespace std;

void circle(int r){
    cout<< "circumference = " << 2*3.14 * r << endl;
    cout<< "area = " << 3.14 * r *r<< endl;
}

int main() {
    int r;
    cin >>r;
    circle(r);
    return 0;
}