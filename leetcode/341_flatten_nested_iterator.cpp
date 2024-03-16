#include <bits/stdc++.h>

using namespace std;

class NestedIterator {
    struct ListPos {
        const vector<NestedInteger>* list;
        int nextPos;
    };

    stack<ListPos> positions;
    int cur;
    bool curFilled;

    void fillCur() {
        if (curFilled)
            return;
        while (true) {
            if (positions.empty())
                return;
            const vector<NestedInteger> &list = *positions.top().list;
            int &nextPos = positions.top().nextPos;
            if (nextPos >= list.size()) {
                positions.pop();
                continue;
            }
            if (list[nextPos].isInteger()) {
                cur = list[nextPos].getInteger();
                curFilled = true;
                ++nextPos;
                return;
            }
            ++nextPos;
            positions.push(ListPos{&list[nextPos-1].getList(), 0});
        }
    }

public:
    NestedIterator(const vector<NestedInteger> &nestedList):
    cur(0), curFilled(false) {
        positions.push(ListPos{&nestedList, 0});
    }

    int next() {
       fillCur();
       if (curFilled) {
           curFilled = false;
           return cur;
       } else {
           throw logic_error("next() called when hasNext() false\n");
       }
    }
    bool hasNext() {
        fillCur();
        return curFilled;
    }
};

int main() {

    return 0;
}
