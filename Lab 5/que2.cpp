#include <bits/stdc++.h>
#include <vector>
using namespace std;

class ArrayProcessor
{
private:
    int *arr;                      // Vector to hold the array elements
    int n;                         // Number of elements in the array
    const int MAX_ITERATIONS = 20; // Maximum number of iterations

public:
    // Constructor to initialize the array size and elements
    ArrayProcessor(int size)
    {
        n = size;
        arr = new int[n];
    }

    // Function to input the elements of the array from the user
    void inputArray(int size)
    {
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    // Function to print reversed or original groups of 3 elements
    // void printReversedGroups()
    // {
    //     vector<int> ans;
    //     int j = 0;
    //     for (int i = 0; i < n * 20; i++)
    //     {
    //         ans.push_back(arr[j]);
    //         j = (j + 1) % n;
    //     }
    //     int k = 0;
    //     for (int k = 0; k + 2 < n * 20; k += 3)
    // {
    //     swap(ans[k], ans[k + 2]);
    // }

    //     for (auto i : ans)
    //     {
    //         cout << i << " ";
    //     }
    // }

    void printReversedGroups()
    {
        int extra = 0;
        if(n%3 == 0) extra = 0;
        else extra = 3;
        int total = (n * 20 / 3) * 3 + extra;
        int count = 0;
        int idx = 0;

        while (count < total)
        {

            vector<int> group;
            for (int i = 0; i < 3 && count + i < total; i++)
            {
                group.push_back(arr[(idx + i) % n]);
            }

            reverse(group.begin(), group.end());

            for (int x : group)
            {
                cout << x << " ";
            }

            // Move forward
            idx = (idx + 3) % n;
            count += 3;
        }
    }
};

int main()
{
    int n;

    // Ask the user for the number of elements in the array

    cin >> n;

    // Create an instance of ArrayProcessor
    ArrayProcessor processor(n);

    // Input the array elements
    processor.inputArray(n);

    // Print the reversed groups
    processor.printReversedGroups();

    return 0;
}