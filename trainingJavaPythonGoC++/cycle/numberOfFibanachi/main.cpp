#include <iostream>

using namespace std;

int main() {
    int a;
    int n = 1; // counter for deducing numbering of Fibonacci number
    int f_0 = 0;
    int f_1 = 1;

    cin >> a;

    while (f_1 < a) {
        int tmp = f_1;

        ++n;
        f_1 += f_0;
        f_0 = tmp;
    }

    if (f_1 == a) {
        cout << n;
    }
    else {
        cout << -1;
    }

    return 0;
}