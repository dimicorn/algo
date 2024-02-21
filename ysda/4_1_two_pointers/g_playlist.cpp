#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) 
        cin >> arr[i];
    unordered_map<int, int> hash;
    int l = 0, r = 0;
    int res = 0;
    while (l <= r && r < n) {
        if (hash.find(arr[r]) == hash.end()) {
            hash[arr[r]] = 1;
            ++r;
        } else {
            ++hash[arr[r]];
            ++r;
        }

        while (r - l > hash.size()) {
            --hash[arr[l]];
            if (hash[arr[l]] == 0) {
                hash.erase(arr[l]);
            }
            ++l;
        }
        res = max(res, r - l);
    }

    cout << res << '\n';
    
    return 0;
}
