#include <iostream>
#include <vector>
#include <cmath>

struct Coord {
    float x;
    float y;
};

float distance(float x1, float x2, float y1, float y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main(int argc, char* argv[]) {
    int n, k;
    float x, y, r, res = 0;
    float pi = 3.1415926;
    std::cin >> n >> r;
    std::vector<Coord*> coords;
    for (int i = 0; i < n; ++i) {
        std::cin >> x >> y;
        Coord* coord = new Coord{x, y};
        coords.push_back(coord);
    }
    k = coords.size();
    for (int i = 1; i < k; ++i) {
        res += distance(coords[i-1]->x, coords[i]->x, coords[i-1]->y, coords[i]->y);
    }
    res += distance(coords[0]->x, coords[k-1]->x, coords[0]->y, coords[k-1]->y);
    res += 2 * pi * r;
    printf("%.2f", res);
    return 0;
}

