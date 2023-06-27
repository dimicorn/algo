#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        while (i < j) {
            if (!(isalpha(s[i]) || isdigit(s[i]))) {
                ++i;
                continue;
            }
            if (!(isalpha(s[j]) || isdigit(s[j]))) {
                --j;
                continue;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    string in1 = "A man, a plan, a canal: Panama";
    string in2 = "race a car";
    string in3 = " ";
    string in4 = "0P";

    Solution sol;

    
    cout << in1 << '\n';
    if (sol.isPalindrome(in1)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }
    cout << "\n\n";
    cout << in2 << '\n';
    if (sol.isPalindrome(in2)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }
    cout << "\n\n";
    cout << in3 << '\n';
    if (sol.isPalindrome(in3)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }
    /*
    cout << in4 << '\n';
    if (sol.isPalindrome(in4)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }
    */
    return 0;
}