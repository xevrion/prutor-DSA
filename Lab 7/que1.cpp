#include <bits/stdc++.h>
using namespace std;

#define INITIAL_CAPACITY 10
#define LOAD_FACTOR 0.7

struct Node {
    int key;
    int value;
    Node* next;
    
    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class HashMap {
public:
    vector<Node*> buckets;
    int capacity;
    int size;

    HashMap() {
        capacity = INITIAL_CAPACITY;
        size = 0;
        buckets.assign(capacity, nullptr);
    }

    unsigned int hash(int key) {
        return abs(key) % capacity;
    }

    void put(int key, int value) {
        // TODO: implement insertion / update
        unsigned int index = hash(key);
        Node* newNode = new Node(key, value);
        if (!buckets[index]) {
            buckets[index] = newNode;
        } else {
            Node* curr = buckets[index];
            while (curr) {
                if (curr->key == key) {
                    curr->value = value;
                    delete newNode;
                    return;
                }
                if (!curr->next) {
                    curr->next = newNode;
                    break;
                }
                curr = curr->next;
            }
        }
        size++;
        if (size / (float)capacity > LOAD_FACTOR) {
            resizeHashMap();
        }
    }

    int get(int key) {
        // TODO: implement lookup
        unsigned int index = hash(key);
        Node* curr = buckets[index];
        while (curr) {
            if (curr->key == key) {
                return curr->value;
            }
            curr = curr->next;
        }
        return -1; // not found
    }

    void removeKey(int key) {
        // TODO: implement deletion
        unsigned int index = hash(key);
        Node* curr = buckets[index];
        Node* prev = nullptr;
        while (curr) {
            if (curr->key == key) {
                if (prev) {
                    prev->next = curr->next;
                } else {
                    buckets[index] = curr->next;
                }
                delete curr;
                size--;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void resizeHashMap() {
        // TODO: implement resizing and rehashing
        int oldCapacity = capacity;
        capacity *= 2;
        vector<Node*> oldBuckets = buckets;
        buckets.assign(capacity, nullptr);
        size = 0;
    }

    ~HashMap() {
        for (int i = 0; i < capacity; i++) {
            Node* node = buckets[i];
            while (node) {
                Node* temp = node;
                node = node->next;
                delete temp;
            }
        }
    }
};

int main() {
    int N;
    cin >> N;

    HashMap map;

    for (int i = 0; i < N; i++) {
        string operation;
        int key, value;
        cin >> operation;

        if (operation == "put") {
            cin >> key >> value;
            map.put(key, value);
            // print the whole hash map, {1=1, 2=3} format
            cout << "{";
            for (int j = 0; j < map.capacity; j++) {
                Node* curr = map.buckets[j];
                while (curr) {
                    cout << curr->key << "=" << curr->value;
                    curr = curr->next;
                    if (curr || j < map.capacity - 1) {
                        cout << ",";
                    }
                }
            }
            cout << "}" << endl;
        } else if (operation == "get") {
            cin >> key;
            cout << map.get(key) << endl;
        } else if (operation == "remove") {
            cin >> key;
            map.removeKey(key);
            cout << "{";
            for (int j = 0; j < map.capacity; j++) {
                Node* curr = map.buckets[j];
                while (curr) {
                    cout << curr->key << "=" << curr->value;
                    curr = curr->next;
                    if (curr || j < map.capacity - 1) {
                        cout << ",";
                    }
                }
            }
            cout << "}" << endl;
        }
    }

    return 0;
}
