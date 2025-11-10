// Closest Pair of Points
// Idea: Sort according to x, then use divide and conquer, cal min dis in right hand and max dis in left hand
// The min dis can be from a point from right hand and a point from a left hand
// so we should take a strip between right and left with condition x - x_mix < min_dis
// compare between min_dis right now and from the strip

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

double cal_dis(pair<int, int> p1, pair<int, int> p2)
{
    int x1 = p1.first;
    int y1 = p1.second;
    int x2 = p2.first;
    int y2 = p2.second;
    double dis = sqrt((pow((x2 - x1), 2)) + (pow((y2 - y1), 2)));

    return dis;
}

// return min distance
double merge_and_sort(vector<pair<int, int>> &v, int l, int r)
{
    // 3 base cases (1 ele, 2 ele, 3 ele)
    if (l == r)
    {
        return INT_MAX;
    }
    else if (l + 1 == r)
    { // 2 elements
        return cal_dis(v[l], v[r]);
    }

    else if (l + 2 == r)
    {
        double dis1 = cal_dis(v[l], v[r]);
        double dis2 = cal_dis(v[l + 1], v[r]);
        double dis3 = cal_dis(v[l], v[l + 1]);
        return min(min(dis1, dis2), dis3);
    }
    int mid = (l + r) / 2;
    pair<int, int> mid_point = v[mid];
    double min_left_dis = merge_and_sort(v, l, mid);
    double min_right_dis = merge_and_sort(v, mid + 1, r);

    double min_d = min(min_left_dis, min_right_dis);

    vector<pair<int, int>> strip;

    for (int i = l; i <= r; i++)
    {
        if (fabs(v[i].first - mid_point.first) < min_d)
        {
            strip.push_back(v[i]);
        }
    }

    for (int i = 0; i < strip.size(); ++i)
    {
        for (int j = i + 1; j < strip.size() && (strip[j].second - strip[i].second) < min_d; ++j)
        {
            min_d = min(min_d, cal_dis(strip[i], strip[j]));
        }
    }

    return min_d;
}

int main()
{
    vector<pair<int, int>> v = {
        {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    sort(v.begin(), v.end());

    cout << merge_and_sort(v, 0, v.size() - 1);

    return 0;
}