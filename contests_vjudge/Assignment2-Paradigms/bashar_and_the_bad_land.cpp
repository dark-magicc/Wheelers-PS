// Idea: Use two pointer method and check all windows where you can collect the amount of gold you needed
// Then choose the narrowest window
// Note: Number of houses = right - left + 1

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main()
{
    int houses, gold; // enter number of houses and amount of gold required to escape from that town
    cin >> houses >> gold;

    vector<int> v(houses);
    for (int i = 0; i < houses; i++)
    {
        cin >> v[i];
    }

    int sum = 0; // sum of collected gold
    int min_number_of_houses = INT_MAX;
    int left = 0;

    // Start the two pointers at first at 0 (L=R=0)
    for (int r = 0; r < houses; r++)
    {
        sum += v[r];
        while (sum >= gold)
        {
            min_number_of_houses = min(min_number_of_houses, r - left + 1); // Check if that window is narrower that the stored window
            sum -= v[left];
            left++;
        }
    }

    if (min_number_of_houses == INT_MAX) // can't collect the required amount of gold
    {
        cout << -1;
    }
    else{
        cout <<min_number_of_houses;
    }
    
    return 0;
}