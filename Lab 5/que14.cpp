#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> A;
    vector<int> B;
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        A.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        B.push_back(temp);
    }

    vector<int> cA;
    vector<int> cB;

    int sumA = 0;
    for (int i = 0; i < n; i++)
    {
        sumA += A[i];
        cA.push_back(sumA);
    }
    int sumB = 0;
    for (int i = 0; i < n; i++)
    {
        sumB += B[i];
        cB.push_back(sumB);
    }

    if (cB[n - 1] == cA[n - 1])
    {
        sort(cA.begin(), cA.end());
        sort(cB.begin(), cB.end());
        int flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (cA[i] != cB[i])
                flag = 0;
        }

        if (flag)
            cout << "yes";
        else
            cout << "no";
    }
    else
        cout << "no";

    return 0;
}