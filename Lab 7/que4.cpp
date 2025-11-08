#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

struct Point
{
    double x, y;
};

// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line. Note: All the points are unique.
//  The first line of input contains the number of points N. The subsequent N lines contain the x, y coordinates of the points. Output should be a single number

// Example 1:
// 3
// 1 1
// 2 2
// 3 3
// Output:
// 3

// Example 2:
// 6
// 1 1
// 3 2
// 5 3
// 4 1
// 2 3
// 1 4

// Output:
// 4

int getMaxPoints(const vector<Point> &points)
{
    int result = 0;
    // Your code goes here
    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        unordered_map<double, int> hash;
        for (int j = i + 1; j < n; j++)
        {
                
            double dy = points[j].y - points[i].y;
            double dx = points[j].x - points[i].x;
            double slope;
            if (dx == 0)
            {
                slope = INT_MAX; // vertical line
            }
            else
            {
                slope = dy / dx;
            }
            // Store the slope in the hash map
            hash[slope]++;
        }
        for(auto it : hash){
            result = max(result, it.second+1);
        }
    }
    return result;
}

int main()
{
    int N;
    cin >> N;

    vector<Point> points(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> points[i].x >> points[i].y;
    }

    int result = getMaxPoints(points);

    cout << result << endl;
    return 0;
}