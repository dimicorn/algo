#include <iostream>

using namespace std;

struct edge {
    int v1, v2;
};

int main(int argc, char* argv[]) {
    int n; // number of vertices
    int m; // number of edges
    cin >> n >> m;
    int vertices[n];
    for (int i = 1; i <= n; ++i) {
        vertices[i-1] = 0;
    }
    edge edges[m];
    for (int i = 0; i < m; ++i) {
        edge e;
        cin >> e.v1 >> e.v2;
        edges[i] = e;
    }
    for (auto &it : edges) {
        vertices[it.v1-1]++;
        vertices[it.v2-1]++;
    }
    for (int i = 0; i < n; ++i) {
        cout << vertices[i] << ' ';
    }
    // cout << '\n';

    return 0;
}

