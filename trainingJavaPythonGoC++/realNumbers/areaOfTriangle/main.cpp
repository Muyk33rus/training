
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;

    cin >> a >> b >> c;

    double p = (a + b + c) / 2.0;

    double square = sqrt(p * (p - a) * (p - b) * (p - c));

    cout << square;

    return 0;
}
