#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

int activityNotifications(int expenditure[], int d, int n) {
    int turns = n-d;
    int j = 1;
    int ans = 0;
    for(int i = 0; i<turns; i++){
        vector<int> hehe;
        for(int k = j-1; k<j+d-1; k++){
            hehe.push_back(expenditure[k]);
        }
        sort(hehe.begin(), hehe.end());
        int median = 0, size = hehe.size();
        if(d%2 == 0){
            median = (hehe[size/2] + hehe[size/2-1])/2;
        } else {
            median = hehe[(size-1)/2];
        }
        if(expenditure[d+j-1] >= 2*median){
            ans++;
        }
        j++;

    }

    return ans;

}

int main() {
    int d, n;
    cin >> n;
    cin >> d;
    
    int expenditure[n];
    for (int i = 0; i < n; i++) {
        cin >> expenditure[i];
    }
    
    int result = activityNotifications(expenditure, d,n);

    cout << result << endl;

    return 0;
}