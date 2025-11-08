#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int id; node* next;

    node(int ai){
        id = ai; next = NULL;
    }
} node;

class LinkedList{
public:
    node* head; node* last;

    LinkedList(node* h){
        head = h;
        last = h;
    }

    void insert(node* ln){
        last->next = ln;
        last = last->next;
    }

    void DisplayList(){
        for(node* c=head;c;c=c->next) cout << c->id << ' ';
        cout << '\n';
    }

    bool find(node* n){
        for(node* c=head;c;c=c->next)
            if(c==n) return true;
        return false;
    }
};

void printHitForkApart(vector<LinkedList>& L){
    int n = L.size();
    // for(auto x : L) x.DisplayList();
    // Complete the function now
    // Hint : Use the find method of Linked List

    int hit = 0, fork = 0, apart = 0;

    vector<set<node*>> pathNodes(n);
    for(int i = 0; i < n; ++i){
        for(node* temp = L[i].head; temp != nullptr; temp = temp->next){
            pathNodes[i].insert(temp);
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            bool hitFound = L[i].find(L[j].head) || L[j].find(L[i].head);
            if(hitFound){
                ++hit;
                continue;
            }

            bool forkFound = false;
            for(auto it : pathNodes[i]){
                if(it != L[i].head && it != L[j].head && pathNodes[j].count(it)){
                    forkFound = true;
                    break;
                }
            }

            if(forkFound){
                ++fork;
            } else {
                ++apart;
            }
        }
    }

    cout << hit << "\n" << fork << "\n" << apart << '\n';

}

// DO NOT ALTER THE CODE BELOW

int main(){
    int n; cin >> n;

    vector<LinkedList> LL;
    map<int,node*> mp;

    for(int i=0;i<n;i++){
        int m; cin >> m;
        int hid; cin >> hid; m--;
 
        if(mp.find(hid)==mp.end()) mp[hid] = new node(hid);
            LL.push_back(LinkedList(mp[hid]));
    
        while(m--){
            int ai; cin >> ai;
            if(mp.find(ai)==mp.end()) mp[ai] = new node(ai);
            LL[i].insert(mp[ai]);
        }
    }

    printHitForkApart(LL);
    return 0;
}