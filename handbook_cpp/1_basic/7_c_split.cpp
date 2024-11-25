#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> Split(const string& str, char delimiter) {
    vector<string> res;
    string tmp = "";
    for (const auto &letter: str) {
        if (letter == delimiter) {
            res.push_back(tmp);
            tmp = "";
        } else {
            tmp += letter;
        }
            
    }
    return res;
}
int main() {
    string str = "What_is_your_name?";
    char delim = '_';

    auto res = Split(str, delim);
    for (const auto &i : res)
        cout << i  << ' ';
}
