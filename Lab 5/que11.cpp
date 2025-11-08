#include <iostream>
#include <vector>

using namespace std;

class ArrayOperations {
private:
    vector<int> *arr1, *arr2;

public:
    // Constructor to initialize arrays
    ArrayOperations(vector<int> &a1, vector<int> &a2) {
        arr1 = &a1;
        arr2 = &a2;
    }

    // Function to merge the arrays alternately and print the result
    void SortNalternatingMerge() {
        // arr1 -> increasing :)
        // arr2 -> decreasing :)
        int n = arr1->size();
        for (int i = 1; i < n; i++)
        {
            int key = (*arr1)[i];
            int j = i - 1;
            while (j >= 0 && (*arr1)[j] > key)
            {
                (*arr1)[j + 1] = (*arr1)[j];
                j--;
            }
            (*arr1)[j + 1] = key;
        }
        n = arr2->size();
        for (int i = 1; i < n; i++)
        {
            int key = (*arr2)[i];
            int j = i - 1;
            while (j >= 0 && (*arr2)[j] < key)
            {
                (*arr2)[j + 1] = (*arr2)[j];
                j--;
            }
            (*arr2)[j + 1] = key;
        }

        // sorted .. now
        if(arr1->size() > arr2->size()){
            for(int i =0 ; i<arr2->size(); i++){
                cout<<(*arr1)[i]<<" ";
                cout<<(*arr2)[i]<<" ";
            }
            for(int i = arr2->size(); i<arr1->size(); i++){
                cout<<(*arr1)[i]<<" ";
                
            }
        } else if(arr1->size() < arr2->size()){
            for(int i =0 ; i<arr1->size(); i++){
                cout<<(*arr1)[i]<<" ";
                cout<<(*arr2)[i]<<" ";
            }
            for(int i = arr1->size(); i<arr2->size(); i++){
                cout<<(*arr2)[i]<<" ";
                
            }

        } else {
            for(int i =0 ; i<arr1->size(); i++){
                cout<<(*arr1)[i]<<" ";
                cout<<(*arr2)[i]<<" ";
            }
        }
        
    }
};

int main() {
    int n1, n2;

    // Reading the size and elements of the first array
    cin >> n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    // Reading the size and elements of the second array
    cin >> n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    // Creating an object of ArrayOperations
    ArrayOperations arrayOps(arr1, arr2);

    // Sorting and Merging and printing the arrays
    arrayOps.SortNalternatingMerge();

    return 0;
}