#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
 
int main()
{
    int c, n, t, w;
    string s, p, q, a, b;
    vector<int> v1, v2, v3, arr;
    cin >> n;
    getline(cin, s);
    getline(cin, p);
    getline(cin, q);
    istringstream is(p);
    int num;
    while(is>>num) v1.push_back(num);
    istringstream is2(q);
    int num2;
    while(is2>>num2) v2.push_back(num2);
    for (int i = 1; i < v1.size(); ++i){
        v3.push_back(v1[i]);
    }
    for (int i = 1; i < v2.size(); ++i){
        v3.push_back(v2[i]);
    }
    for (int i = 0; i < v3.size(); ++i){
        for (int j = i+1; j < v3.size(); ++j){
            if (v3[i] == v3[j]){
                v3.erase(v3.begin()+j);
            }
        }
    }
    if (v3.size() == n){
        cout << "I become the guy.";
    }
    else{
        cout << "Oh, my keyboard!";
    }
    return 0;
}
