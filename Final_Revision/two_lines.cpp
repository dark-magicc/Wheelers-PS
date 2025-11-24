#include <iostream>
using namespace std;
struct C_point
{
    double x;
    double y;
};

int main()
{
    C_point p1, p2, p3, p4;

    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cin >> p3.x >> p3.y >> p4.x >> p4.y;

    if ((p2.y - p1.y) * (p4.x - p3.x) == (p4.y - p3.y) * (p2.x - p1.x))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}