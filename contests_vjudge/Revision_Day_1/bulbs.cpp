// Idea: To use set to prevent dublicated
// Print Yes only if you can turn on all bulbs using the buttons
#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, m; // Number of buttons: N,  Number of bulbs: M
    cin >> n >> m;
    set<int> s; // to store turn on leds
    for (int i = 0; i < n; i++)
    {
        int x; // for each button, user will enter number of bulbs he can turn on using that button, then will enter which bulb
        cin >> x;
        for (int i = 0; i < x; i++)
        {
            int b;
            cin >> b;
            s.insert(b);
        }
    }

    if (s.size() == m)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}