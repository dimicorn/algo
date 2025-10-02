#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int full_bottles = numBottles;
        int empty_bottles = 0;
        int bottles_drunk = 0;
        while (!(full_bottles == 0 && empty_bottles < numExchange)) {
            if (full_bottles != 0) {
                bottles_drunk += full_bottles;
                empty_bottles += full_bottles;
                full_bottles = 0;
            } else {
                empty_bottles -= numExchange;
                ++full_bottles;
                ++numExchange;
            }
        }
        return bottles_drunk;
    }
};
