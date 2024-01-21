#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key, val;
    Node *prev, *next;
    Node(int key, int val): key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity): cap(capacity) {
        // left - LRU, right - most recent
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = right->prev;
        Node* nxt = right;
        prev->next = nxt->prev = node;
        node->next = nxt;
        node->prev = prev;
    }
        
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
       if (cache.find(key) != cache.end()) {
           remove(cache[key]);
       }
       cache[key] = new Node(key, value);
       insert(cache[key]);

       if (cache.size() > cap) {
           Node* lru = left->next;
           remove(lru);
           cache.erase(lru->key);
       }
    }
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left, *right;
};

int main() {

    return 0;
}
