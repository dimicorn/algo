#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<long long> nums = {INT_MIN};
        nums.insert(nums.end(), arr.begin(), arr.end());
        nums.push_back(INT_MIN);
        int n = nums.size(); 
        
        stack<int> st;
        long long res = 0;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                int mid = st.top();
                st.pop();
                int left = st.top();
                int right = i;

                res += nums[mid] * (mid - left) * (right - mid);
            }
            st.push(i);
        }
        return res % 1000000007;
    }
};

int main() {
    vector<int> arr = {3,1,2,4};
    Solution* sol = new Solution();
    cout << sol->sumSubarrayMins(arr) << '\n';
    
    return 0;
}
