// Given a set of characters and their frequencies, build a Huffman Tree and generate Huffman codes for each character.

// Rules:

// 1 Use a min-heap to repeatedly combine the two nodes with the lowest frequencies.

// 2 The combined node has frequency equal to the sum of the two nodes.

// 3 Continue until there is only one node left, the root of the Huffman Tree.

// 4 Assign 0 to left edge and 1 to right edge when traversing.

// 5 Output Huffman codes for all characters.

// Sample input:
// 5
// a b c d e
// 5 9 12 13 16

// Expected output:
// a: 100
// b: 101
// c: 00
// d: 01
// e: 11

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) { ch = c; freq = f; left = right = nullptr; }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        // TODO: return true if a.freq > b.freq Done
        if(a->freq > b->freq) return true;
        return false;
    }
};

class Huffman {
private:
    Node* root;

    void generateCodes(Node* node, string code, unordered_map<char,string>& codes) {
        // TODO: Recursively generate codes for each leaf
        if (!node) return; // if root doesnt exist we return directly.
        
        // if both root's left node annd root's right node dont exist, just asign the code directly. // terminating condition for the recursive function.
        if (!node->left && !node->right) { 
            codes[node->ch] = code;
            return;
        }
        
        // Recursive Part
        generateCodes(node->left, code + "0", codes);
        generateCodes(node->right, code + "1", codes);
    }

public:
    Huffman(vector<char>& chars, vector<int>& freq) {
        // TODO: Build Huffman Tree using min-heap
        
        // root = nullptr;
        
        priority_queue<Node*, vector<Node*>, Compare> pQueue;

        for (int i = 0; i < chars.size(); i++) {
            pQueue.push(new Node(chars[i], freq[i]));
        }
    
        while (pQueue.size() > 1) {
            Node* L = pQueue.top();pQueue.pop();
            Node* R = pQueue.top();pQueue.pop();
    
            Node* finalMerged = new Node('$', L->freq + R->freq);
            finalMerged->left = L;
            finalMerged->right = R;
    
            pQueue.push(finalMerged);
        }
    
        root = pQueue.top();
        // root = nullptr;

    }

    void printCodes() {
        unordered_map<char,string> codes;
        generateCodes(root, "", codes);
        // TODO: print codes for each character Done
        vector<pair<char, string>> sorted(codes.begin(), codes.end());
        sort(sorted.begin(), sorted.end());
        
        
        for (auto& pair : sorted) {
        cout << pair.first << ": " << pair.second << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<char> chars(n);
    vector<int> freq(n);
    for (int i = 0; i < n; i++) cin >> chars[i];
    for (int i = 0; i < n; i++) cin >> freq[i];

    Huffman h(chars, freq);
    h.printCodes();

    return 0;
}

