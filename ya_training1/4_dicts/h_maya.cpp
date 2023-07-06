#include <bits/stdc++.h>

using namespace std;

int main() {
    int g, s;
    string word, sentence;
    cin >> g >> s;
    cin >> word >> sentence;
    int count = 0;
	vector<int> freq(52, 0), window(52, 0);
	for (auto &i : word) {
		if ('A' <= i && i <= 'Z') {
			freq[i-'A']++;
		} else {
			freq[i-'A'-('a'-'Z')+1]++;
		}
	}
	for (int i = 0; i < g; ++i) {
		if ('A' <= sentence[i] && sentence[i] <= 'Z') {
			window[sentence[i]-'A']++;
		} else {
			window[sentence[i]-'A'-('a'-'Z')+1]++;
		}
	}
	// cout << word << ' ' << sentence << '\n';
	if (freq == window) {
		count++;
	}
	for (int i = g; i < s; ++i) {
		if ('A' <= sentence[i-g] && sentence[i-g] <= 'Z') {
			window[sentence[i-g]-'A']--;
		} else {
			window[sentence[i-g]-'A'-('a'-'Z')+1]--;
		}

		if ('A' <= sentence[i] && sentence[i] <= 'Z') {
			window[sentence[i]-'A']++;
		} else {
			window[sentence[i]-'A'-('a'-'Z')+1]++;
		}
		if (window == freq) {
			count++;
		}
	}
	cout << count << '\n';

    return 0;
}
