#include <iostream>
#include <cmath>

double distance(double v, double a) {
    const double g = 10;
    const double pi = 3.1415926535;
    double phi = a * pi / 90;
    return sin(phi) * v * v / g;
}


int main(int argc, char *argv[]) {
    double v, a;
    double k, length = 0;
    std::cin >> v >> a >> k;
    double d = distance(v, a);
    length += d;
    while (d > 0.00000000001) {
        v /= sqrt(k);
        d = distance(v, a);
        length += d;
    }
    printf("%.2lf", length);
    return 0;
}

