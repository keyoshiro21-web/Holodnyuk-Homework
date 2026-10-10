
#include <iostream>
using namespace std;

double myPow(double x, int n) {
    if (n == 0) {
        return 1.0;
    }

    if (n < 0) {
        return 1.0 / myPow(x, -(n + 1)) / x;
    }

    double half = myPow(x, n / 2);

    if (n % 2 == 0) {
        return half * half;
    }

    return half * half * x;
}

int main() {
    double x = 2.0;
    int n = -2;

    cout << myPow(x, n) << endl;

    return 0;
}
