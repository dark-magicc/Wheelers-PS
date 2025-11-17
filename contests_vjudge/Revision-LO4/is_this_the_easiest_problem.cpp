// Idea: Given 3 sides,
// Use the triangle inquality theorem to make sure it is a traingle (sum of 2 sides are greater that the third side)
// if a triangle: check if Equilateral or Isosceles or Scalene

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int index = 1;
    while (t-- > 0)
    {
        double a, b, c;
        cin >> a >> b >> c;
        if (a+b > c && a+c > b && b+c > a)
        {
            if ((a == b) && (a == c))
            {
                cout << "Case " << index <<": " << "Equilateral" << endl;
            }
            else if (a == b || a == c || b == c){
                cout << "Case " << index <<": " << "Isosceles" << endl;
            }
            else{
                cout << "Case " << index <<": " << "Scalene" << endl;
            }
        }
        else{
            cout << "Case " << index <<": " << "Invalid" << endl;
        }
        index++;
    }

    return 0;
}