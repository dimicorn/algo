#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int l, r, k, n, q, t;
    cin >> t;
    vector<string> ans;
    for (int i = 0; i < t; ++i) {
        cin >> n >> q;
        int arr[n];
        int prefix[n+1];
        prefix[0] = 0;
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        for (int j = 1; j <= n; ++j) {
            prefix[j] = prefix[j-1] + arr[j-1];
        }
        for (int j = 0; j < q; ++j) {
            cin >> l >> r >> k;
            --l;
            int sum1 = prefix[r] - prefix[l];
            int sum2 = (r-l) * k;
            int sum = prefix[n] - sum1 + sum2;
            if (sum % 2 != 0) {
                ans.push_back("YES");
            } else {
                ans.push_back("NO");
            }
        }
    }
 
    for (auto const &it : ans) {
        cout << it << '\n';
    }
    return 0;
}
