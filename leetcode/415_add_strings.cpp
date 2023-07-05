#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.length() < num2.length()) {
            swap(num1, num2);
        }   
        int i = num1.length()-1;
        int j = num2.length()-1;
        int carry = 0;
        string ans = ""; 
        while (i >= 0) {
            if (j < 0) {
                int temp = num1[i]-'0'+carry;
                if (temp > 9) {
                    ans += to_string(temp%10);
                    carry = 1;
                } else {
                    ans += to_string(temp);
                    carry = 0;
				}
                ++j;
            } else {
                int temp = (num1[i]-'0') + (num2[j]-'0') + carry;
                if (temp > 9) {
                    ans += to_string(temp%10);
                    carry = 1;
                } else {
                    ans += to_string(temp);
                    carry = 0;
                }   
            }   
            --i;
            --j;
        }   
        if (carry == 1) {
            ans += to_string(carry);
        }   
        reverse(ans.begin(), ans.end());
        return ans;
    }   
};

int main(int argc, char* argv[]) {
	string num1 = "11";
	string num2 = "123";
	Solution sol;
	string ans = sol.addStrings(num1, num2);
	cout << ans << '\n';

	num1 = "456";
	num2 = "77";
	ans = sol.addStrings(num1, num2);
	cout << ans << '\n';

	num1 = "0";
	num2 = "0";
	ans = sol.addStrings(num1, num2);
	cout << ans << '\n';

	return 0;
}
