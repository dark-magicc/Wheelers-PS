// Check if a triangle is right angle or not (c^2 == a^2 + b^2)

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    while (true)
    {
        double sides[3];
        for (int i = 0; i < 3; i++)
        {
            cin >> sides[i];
        }
        if (0 ==  sides[0] == sides[1] == sides[2])
        {
            break;
        }
        sort(sides, sides+3);
        if (sides[0]* sides[0] + sides[1]* sides[1] == sides[2] * sides[2])
        {   
            cout << "right" << endl;
        }
        else{
            cout << "wrong" << endl;
        }
        
    }
    return 0;
}