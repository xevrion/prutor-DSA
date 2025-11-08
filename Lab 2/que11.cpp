#include <iostream>
#include <vector>
using namespace std;

class Game {
private:
    int x; // Number of students
    int n; // Initial student who gets the paper
    int p; // Steps to pass the paper

public:

    Game(int x, int n, int p) : x(x), n(n), p(p) {}

    int findwinner() {
        //code here
        vector<int> Students(x,0);
        int count = 0;
        int temp = x;
        int rem = n;
        while(x != 1){
            if(rem > temp-1){
                rem -= temp;
            }
            
            if(Students[rem] == 0){
                count++;
            }


            
            
            if(Students[rem] == 0 && count == p){
                Students[rem] = 1;
                x--;
                count = 0;
                
            }
            // else{
            //     while(Students[rem] != 0){
            //         rem++;
            //         if(rem > x-1){
            //             rem -= temp;
            //         }
                    
            //     }
            //     Students[rem] = 1;
            //     count = 0;
            //     x--;
                
            // }
            
            
            rem++;
        }
        
        for(int i =0 ; i<temp; i++){
            if(Students[i] == 0){
                return i+1;
            }
        }

    }
};

int main() {
    int T;
    cin >> T; 

    while (T--) {
        int x, n, p;
        cin >> x >> n >> p;
        Game temp(x,n,p);
        cout<<temp.findwinner()<<endl;
    }

    return 0;
}