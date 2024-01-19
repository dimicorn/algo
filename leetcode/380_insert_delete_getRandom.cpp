#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
public:
unordered_map<int, int> map;
vector<int> v;
    RandomizedSet() {}
    
    bool insert(int val) {
        if (map.find(val) == map.end()) {
            v.push_back(val);
            map[val] = v.size()-1;
            return true;
        } else {
            return false;
        }
    }
    
    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false;
        } else {
            map[v[v.size()-1]] = map[val];
            iter_swap(v.begin()+map[val], v.begin() + v.size()-1);
            v.pop_back();
            map.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

int main() {
    RandomizedSet* obj = new RandomizedSet();
    if (obj->insert(0)) cout << "true "; else cout << "false ";
    if (obj->insert(1)) cout << "true "; else cout << "false ";
    if (obj->remove(0)) cout << "true "; else cout << "false ";
    if (obj->insert(2)) cout << "true "; else cout << "false ";
    if (obj->remove(1)) cout << "true "; else cout << "false ";
    cout << obj->getRandom() << '\n';
    
    return 0;
}
