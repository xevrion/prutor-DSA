#include <bits/stdc++.h>
using namespace std;

// -----------------------------
// Node class representing each location in the treasure map
// -----------------------------
class Node {
public:
    int val;         // treasure value
    Node* next;      // main path pointer
    Node* secret;    // side path pointer

    Node(int value) {
        val = value;
        next = nullptr;
        secret = nullptr;
    }
};

// -----------------------------
// TreasureMap class to handle building and flattening
// -----------------------------
class TreasureMap {
public:
    unordered_map<int, Node*> nodes; // stores treasure value -> Node pointer

    // Ensure node exists in the map
    Node* getNode(int value) {
        if (!nodes.count(value)) {
            nodes[value] = new Node(value);
        }
        return nodes[value];
    }

    // Build the treasure map from given connections
    // Modified to just create nodes, edges set outside
    void buildNodes(const vector<tuple<int,int,int>>& edges) {
        for (auto& e : edges) {
            int u, v, type;
            tie(u,v,type) = e;
            getNode(u);
            getNode(v);
        }
    }

    // Connect edges
    void connectEdges(const vector<tuple<int,int,int>>& edges) {
        for (auto& e : edges) {
            int u, v, type;
            tie(u,v,type) = e;
            Node* from = nodes[u];
            Node* to = nodes[v];
            if (type == 0) {
                // connect from->next to to
                from->next = to;
            } else {
                // connect from->secret to to
                from->secret = to;
            }
        }
    }

    // Flatten the treasure map
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        stack<Node*> stk;
        stk.push(head);

        Node* dummy = new Node(-1); // dummy head to ease linking
        Node* curr = dummy;

        while (!stk.empty()) {
            Node* node = stk.top();
            stk.pop();

            curr->next = node;
            curr = curr->next;

            // Push next first, then secret, so secret is processed first
            if (node->next) stk.push(node->next);
            if (node->secret) stk.push(node->secret);

            // Remove secret pointer after flattening
            node->secret = nullptr;
        }

        curr->next = nullptr;
        Node* flatHead = dummy->next;
        delete dummy;
        return flatHead;
    }

    // Print the treasure path
    void printPath(Node* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << "NULL\n";
    }
};

// -----------------------------
// Main function
// -----------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        TreasureMap mapObj;

        vector<tuple<int,int,int>> edges;
        for (int i = 0; i < N ; i++) {
            int u, v, type;
            cin >> u >> v >> type;
            edges.emplace_back(u, v, type);
        }

        // Build nodes first
        mapObj.buildNodes(edges);

        // Calculate indegree to find start node (no incoming edges)
        unordered_map<int,int> indeg;
        for (auto& [u,v,type] : edges) {
            indeg[v]++;
        }

        // Find the node with zero indegree to start flattening
        Node* startNode = nullptr;
        for (auto& [val, nodeptr] : mapObj.nodes) {
            if (indeg[val] == 0) {
                startNode = nodeptr;
                break; // assume unique start
            }
        }

        // Connect edges now
        mapObj.connectEdges(edges);

        // Flatten and print
        Node* flatHead = mapObj.flatten(startNode);
        mapObj.printPath(flatHead);
    }

    return 0;
}
