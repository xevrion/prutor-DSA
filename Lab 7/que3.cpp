#include <bits/stdc++.h>
using namespace std;

#define MAX_LEN 101

// Structure for a node in the hash table
struct Node {
    string key;
    string value;
    Node* next;
};

// Function to create a new node
Node* createNode(string key, string value) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a key-value pair into the hash table
void insert(vector<Node*>& hashTable, string key, string value) {
    int index = 0;
    for (char c : key) {
        index += c;
    }
    index %= 1000; // Assuming the length of input array will be at most 1000

    if (hashTable[index] == nullptr) {
        hashTable[index] = createNode(key, value);
    } else {
        Node* temp = hashTable[index];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = createNode(key, value);
    }
}

// Function to group anagrams
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<Node*> hashTable(1000, nullptr); // Hash table to store groups of anagrams
    int returnSize = 0;
    
    // Insert each word into the hash table based on its sorted characters
    for (const string& str : strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        insert(hashTable, sortedStr, str);
    }
   
    
    // Count the number of groups
    for (const auto& entry : hashTable) {
        if (entry != nullptr) {
            returnSize++;
        }
    }

    // Allocate memory for the result
    vector<vector<string>> result;
    
    // Fill the result array with groups of anagrams
    for (const auto& entry : hashTable) {
        if (entry != nullptr) {
            vector<string> group;
            Node* temp = entry;
            while (temp != nullptr) {
                group.push_back(temp->value);
                temp = temp->next;
            }
            result.push_back(group);
        }
    }

    return result;
}
    
    
// Function to free memory allocated for the result
void freeResult(vector<vector<string>>& result) {
    result.clear();
}

// Function to print the result
void printResult(const vector<vector<string>>& result) {
    for (const auto& group : result) {
        cout << "[";
        for (size_t j = 0; j < group.size(); j++) {
            cout << "\"" << group[j] << "\"";
            if (j != group.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]\n";
    }
}

int main() {
    int n;
    // printf("Enter the number of strings: ");
    cin >> n;
    
    vector<string> strs(n);
    // printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    
    int returnSize;
    vector<int> returnColumnSizes;
    
    vector<vector<string>> result = groupAnagrams(strs);
    
    // Print the result
    // printf("Anagram Groups:\n");
    for (const auto& group : result) {
        cout << "[";
        for (size_t j = 0; j < group.size(); j++) {
            cout << "\"" << group[j] << "\"";
            if (j != group.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]\n";
    }
    
    // Free memory
    freeResult(result);
    
    return 0;
}
