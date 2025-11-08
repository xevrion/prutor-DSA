#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode* sublist;

    ListNode(int x) : val(x), next(nullptr), sublist(nullptr) {}
};

// Function to combine elements of all sublists level by level
ListNode* combineListsLevelByLevel(vector<ListNode*>& subLists, int max) {
    // write your code here
    ListNode* ans = new ListNode(0);
    ListNode* dummy = ans;
    for(int i =0 ; i<max; i++){
        for(int j = 0; j<subLists.size(); j++){
            if(subLists[j]!= NULL){
                dummy->next = subLists[j];
                dummy= dummy->next;
                subLists[j] = subLists[j]->next;
            }
        }
    }

    return ans->next;
   
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    // cout << "Enter the number of sub-linked lists: ";
    cin >> n;
    int maxEle;

    vector<ListNode*> subLists(n, nullptr);

    for (int i = 0; i < n; ++i) {
        int size;
        cin >> size;
        maxEle = max(maxEle, size);

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        for (int j = 0; j < size; ++j) {
            int val;
          
            cin >> val;
            current->next = new ListNode(val);
            current = current->next;
        }

        subLists[i] = dummy->next;
    }

    ListNode* combinedHead = combineListsLevelByLevel(subLists, maxEle);

   
    printList(combinedHead);

    return 0;
}