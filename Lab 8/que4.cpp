// Given an integer n and a 2D array meetings[][], where n represents the number of classrooms numbered from 0 to n - 1, and meetings[i] = [starti, endi] represents a meeting scheduled from start to end. Find the room number that hosts the most meetings. If multiple rooms have the same highest number of meetings, return the smallest room number among them.

// Meeting Allocation Rules

//     When a meeting starts, assign it to the available room with the smallest number.
//     If no rooms are free, delay the meeting until the earliest room becomes available. The delayed meeting retains its original duration.
//     When a room becomes free, assign it to the delayed meeting with the earliest original start timing.

// Note: A person can also attend a meeting if it's starting time is same as the previous meeting's ending time.

// Examples:

//     Input: n=2, meetings[][]=[[0, 6], [2, 3], [3, 7], [4, 8], [6, 8]]
//     Output: 1
//     Explanations: 
//     Time 0: Both rooms available. [0,6] starts in room 0.
//     Time 2: Room 0 busy until 6. Room 1 available. [2,3] starts in room 1.
//     Time 3: Room 1 frees up. [3,7] starts in room 1.
//     Time 4: Both rooms busy. [4,8] is delayed.
//     Time 6: Room 0 frees up. Delayed [4,8] starts in room 0 [6,10).
//     Time 6: [6,8] arrives but both rooms busy. It’s delayed.
//     Time 7: Room 1 frees up. Delayed [6,8] starts in room 1 [7,9).
//     Room 1 hosted 3 meetings which is maximum.

//     Input: n = 4, meetings[][] = [[0, 8], [1, 4], [3, 4], [2, 3]
//     Output: 2
//     Explanation:
//     Time 0: All rooms available. [0,8] starts in room 0.
//     Time 1: Room 0 busy until 8. Rooms 1, 2, 3 available. [1,4] starts in room 1.
//     Time 2: Rooms 0 and 1 busy. Rooms 2, 3 available. [2,3] starts in room 2.
//     Time 3: Room 2 frees up. [3,4] starts in room 2.
//     Room 2 hosted 2 meetings which is maximum.

#include <bits/stdc++.h>
using namespace std;

class MeetingScheduler {
private:
    int n; // number of rooms
    vector<vector<int>> meetings;

public:
    MeetingScheduler(int numRooms, vector<vector<int>>& meet) {
        n = numRooms;
        meetings = meet;
    }

    int mostBooked() {
        // TODO: Implement the logic to find the most booked room
        // Hints:
        // 1. Use min-heap for available rooms
        // 2. Use min-heap for occupied rooms with end times
        // 3. Sort meetings by start time
        // 4. Track count of meetings per room
        sort(meetings.begin(), meetings.end());
        
        priority_queue<int, vector<int>, greater<int>> avl;
        for (int i = 0; i < n; i++) avl.push(i);
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> ocp;

        vector<int> cnter(n, 0);
    
        for (auto& meets : meetings) {
            long long begin = meets[0], finish = meets[1];

            while (!ocp.empty() && ocp.top().first <= begin) {
                avl.push(ocp.top().second);
                ocp.pop();
            }
    
            if (avl.empty()) {
                long long end = ocp.top().first;
                int room = ocp.top().second;
                ocp.pop();
                long long drn = finish - begin;
                begin = end;
                finish = begin + drn;
                avl.push(room);
                avl.pop();
                cnter[room]++;
                ocp.push({finish, room});
            } else {
                int room = avl.top();
                avl.pop();
                cnter[room]++;
                ocp.push({finish, room});
            }
        }
    
        int maxi = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (cnter[i] > maxi) {
                maxi = cnter[i];
                ans = i;
            }
        }
        return ans;
        
        
        
        return 0; // placeholder
    }
};

int main() {
    int n, m;
    cin >> n >> m; // number of rooms and number of meetings

    vector<vector<int>> meetings(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        cin >> meetings[i][0] >> meetings[i][1]; // start and end times
    }

    MeetingScheduler scheduler(n, meetings);

    cout << scheduler.mostBooked() << endl;

    return 0;
}