#include <iostream>
#include <string>

using namespace std;

double gc(string s) {
    double count = 0;
    for (auto &i : s) {
        if (i == 'C' || i == 'G') {
            count++;
        }
    }
    return (count / s.length()) * 100;
}

int main(int argc, char* argv[]) {
    double max_gc = -1;
    double tmp;
    string max_name;
    /* FASTA PARSER */
    string line, name, content;
    while (getline(cin, line)) {
        if (line.empty() || line[0] == '>') {
            if (!name.empty()) {
                tmp = gc(content);
                if (max_gc < tmp) {
                   max_gc = tmp;
                   max_name = name;
                }
                // cout << name << " : " << content << '\n';
                name.clear();
            }
            if (!line.empty()) {
                name = line.substr(1);
            }
            content.clear();
        } else if(!name.empty()) {
            if (line.find(' ') != string::npos) {
                name.clear();
                content.clear();
            } else {
                content += line;
            }
        }
    }
    if (!name.empty()) {
        tmp = gc(content);
        if (max_gc < tmp) {
            max_gc = tmp;
            max_name = name;
        }
        // cout << name << " : " << content << '\n';
    }

    cout << max_name << '\n' << max_gc;

    return 0;
}

