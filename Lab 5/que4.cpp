#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
class SubListFinder {
public:
    SubListFinder(const T* arr) : arr(arr), n(strlen(arr)) {}

    void findSublists() const {
        // cout<<sizeof(arr)<<endl;
        // cout<<arr<<endl;
        for(int i = 0; i<n; i++) {
            if(arr[i+1] == arr[i] && i+1<n){
                cout << arr[i] << arr[i+1] <<", ";
            }
            if(arr[i+2] == arr[i] && i+2<n){
                cout << arr[i] << arr[i+1] << arr[i+2] <<", ";
            }
        }
    }

private:
    const T* arr;
    int n;
};

int main() {
    char input[100001]; 
    cin >> input;
    SubListFinder<char> finder(input);
    finder.findSublists();

    return 0;
}