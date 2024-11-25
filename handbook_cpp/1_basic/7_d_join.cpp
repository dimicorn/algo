#include <string>
#include <vector>

using namespace std;

string Join(const vector<string>& tokens, char delimiter) {
    string res = "";
    int n = tokens.size();
    for (int i = 0; i < n; ++i) {
        res += tokens[i];
        if (i != n - 1)
            res += delimiter;
    }
    return res;
}
