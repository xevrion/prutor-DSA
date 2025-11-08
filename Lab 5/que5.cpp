#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void RollingDice(int n, vector<int> diceRolls)
    {
        vector<int> players(n);
        for (int i = 0; i < n; i++)
        {
            players[i] = i + 1;
        }
        // int deadP = 0;
        int dieThrow = n - 1;
        int thrower = 0;
        int die = 0;
        int i = 0;
        while (dieThrow)
        {
            // die = (die + 1) % n;

            // die = thrower + 1;
            die = (die + diceRolls[i]) % n;
             cout<<diceRolls[i]<<" "<<players[die]<<endl;
            
            players.erase(players.begin() + die);
            
            // deadP ++;
            n--;
            if (die == n) die = 0; 

            // thrower = die + 1;
            i++;
            dieThrow--;
            
            // cout<<i<<endl;
        }

        for (auto i : players)
        {
            cout << i << endl;
        }
    }
};

int main()
{
    int n;
    cin >> n;

    // The array to store the dice rolls
    vector<int> diceRolls(n - 1);

    // Input dice rolls
    for (int i = 0; i < n - 1; i++)
    {
        cin >> diceRolls[i];
    }

    Solution s;
    s.RollingDice(n, diceRolls);

    return 0;
}