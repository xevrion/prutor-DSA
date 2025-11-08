#include <iostream>
#include <vector>
using namespace std;

//Write a program to sort a list of n integers in ascending order using the Heap Sort algorithm.

// Requirements:

// Construct a max-heap from the given array.

// Repeatedly extract the maximum element from the heap and place it at the end of the array.

// Ensure that the array is sorted in ascending order at the end.

// The implementation should not use any built-in sorting functions.

// Input Format:

// The first line contains an integer n, the number of elements.

// The second line contains n space-separated integers.

// Output Format:

// Print the sorted array in ascending order.

class HeapSort {
private:
    vector<int> arr;

    // TODO: Write the heapify function here
    void heapify(int n, int i) {
        // Your code here
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        
        if(left < n && arr[left] > arr[largest]) largest = left;
        
        if(right < n && arr[right] > arr[largest]) largest = right;
        
        if(largest != i){
            swap(arr[i], arr[largest]);
            
            heapify(n,largest);
        }
    }

public:
    // TODO: Constructor to initialize arr
    HeapSort(const vector<int>& input) {
        // Your code here
        arr = input;
    }

    // TODO: Implement the sort() function
    void sort() {
        // Step 1: Build a max heap
        // Step 2: Repeatedly extract the largest element and rebuild heap
        int n = arr.size();
        
        for(int i = n/2 -1; i>=0; i--){ // building max heap
            heapify(n,i);
        }
        for(int i= n-1; i>0; i--){ // extracting max element from the max heap and putting it at the end.. and forgetting about the end :)
            swap(arr[0], arr[i]);
            heapify(i,0);
        }
    }

    // TODO: Implement display() function
    void display() const {
        // Print array elements separated by spaces
        for(int num : arr){
            cout<<num<<" ";
        }
        cout<<endl;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];

    // TODO: Create HeapSort object, call sort(), and display()
    HeapSort h(input);
    h.sort();
    h.display();
    
    return 0;
}