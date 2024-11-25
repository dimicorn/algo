#include <string>
#include <vector>
using namespace std;

string prefix(const string &str1, const string &str2) {
    string pref = "";
    int i = 0;
    int n = str1.length();
    int j = 0;
    int m = str2.length();
    while (i < n && j < m && str1[i] == str2[j]) {
        pref += str1[i];
        ++i;
        ++j;
    }
    return pref;
}

string CommonPrefix(const vector<string>& words) {
    int n = words.size();
    if (n == 0)
        return "";
    if (n == 1)
        return words[0];
    
    string pref = prefix(words[0], words[1]);
    for (int i = 2; i < n; ++i)
        pref = prefix(words[i], pref);
    return pref;
}
