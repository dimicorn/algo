#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.length(), m = searchWord.length();
        int j, k;
        int word_count = 1;
        for (int i = 0; i < n; ++i) {
            j = i;
            k = 0;
            if (sentence[i] == ' ')
                ++word_count;
            while ((i == 0 || sentence[i-1] == ' ') && sentence[j] == searchWord[k] && j < n && k < m) {
                ++k;
                ++j;
            }
            if (k == m)
                return word_count;
        }
        return -1;
    }
};
