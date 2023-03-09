#include <bits/stdc++.h>
 
using namespace std;
 
long long smallestNumber(long long n) {
    if (n == 0) {
        return 10;
    } else if (n > 0 && n <= 9) {
        return n;
    }
     
    // stack the store the digits
    stack<int> digits;
     
    // repeatedly divide 'n' by the numbers
    // from 9 to 2 until all the numbers are
    // used or 'n' > 1
    for (int i = 9; i >= 2 && n > 1; --i) {
        while (n % i == 0) {
            digits.push(i);
            n = n / i;
        }
    }
     
    // if true, then no number 'k' can be formed
    if (n != 1) {
        return -1;
    }
 
    // pop digits from the stack 'digits'
    // and add them to 'k'
    long long k = 0;
    while (!digits.empty()) {
        k = k * 10 + digits.top();
        digits.pop();
    }
    return k;
}
 
int main(int argc, char *argv[]) {
    long long n;
    cin >> n;
    cout << smallestNumber(n);
    return 0;
}
