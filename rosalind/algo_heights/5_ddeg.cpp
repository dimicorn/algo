#include <iostream>

using namespace std;

struct edge {
    int v1, v2;
};

int main(int argc, char* argv[]) {
    int n, m;
    cin >> n >> m;
    edge edges[m];
    int neighbors[n] = {0};
    int res[n] = {0};
    for (int i = 0; i < m; ++i) {
        edge e;
        cin >> e.v1 >> e.v2;
        edges[i] = e;
    }
    for (auto &it : edges) {
        neighbors[it.v1-1]++;
        neighbors[it.v2-1]++;
    }
    for (auto &it : edges) {
        res[it.v1-1] += neighbors[it.v2-1];
        res[it.v2-1] += neighbors[it.v1-1];
    }
    for (auto &i : res) {
        cout << i << ' ';
    }
    return 0;
}

