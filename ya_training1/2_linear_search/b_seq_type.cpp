#include <iostream> 
#include <vector>
#include <string>

std::string check(std::vector<int> v) {
    int con = 0, asc = 0, wasc = 0;
    int desc = 0, wdesc = 0;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i - 1] == v[i]) {
            con++;
        }
        if (v[i - 1] < v[i]) {
            asc++;
        }
        if (v[i - 1] <= v[i]) {
            wasc++;
        }
        if (v[i - 1] > v[i]) {
            desc++;
        } 
        if (v[i - 1] >= v[i]) {
            wdesc++;
        }
    }
    if (con == v.size() - 1) {
        return "CONSTANT\n";
    } else if (asc == v.size() - 1) {
        return "ASCENDING\n";
    } else if (desc == v.size() - 1) {
        return "DESCENDING\n";
    } else if (wasc == v.size() - 1) {
        return "WEAKLY ASCENDING\n";
    } else if (wdesc == v.size() - 1) {
        return "WEAKLY DESCENDING\n";
    } else {
        return "RANDOM\n";
    }
}

int main(int argc, char* argv[]) {
    int n;
    std::vector<int> v;
    while (std::cin >> n && n != -2 * 1000000000) {
       v.push_back(n);
    } 
    std::cout << check(v);
    return 0;
}

