// Idea: Sort the puzzels then use sliding window approach to get the minimum difference between first puzzle and last puzzle
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int num_of_students, num_of_puzzels;
    cin >> num_of_students >> num_of_puzzels;

    vector<int> puzzels(num_of_puzzels);
    for (int i = 0; i < num_of_puzzels; i++)
    {
        cin >> puzzels[i];
    }
    sort(puzzels.begin(), puzzels.end());

    int left = 0;
    int min_diff = INT_MAX;
    // Use two pointers (l=0 r=students-1 at first) (sliding window)
    for (int r = num_of_students-1; r < num_of_puzzels; r++)
    {
        int min_n = puzzels[left];
        int max_n = puzzels[r];
        
        left++;
        min_diff = min(min_diff, max_n-min_n);
    }
    cout << min_diff;

    return 0;
}