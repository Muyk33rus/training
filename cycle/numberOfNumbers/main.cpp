#include <iostream>

using namespace std;

int main() {
    int n = 0;
    int tmp;

    while (cin >> tmp && tmp != 0) {
        ++n;
    }

    cout << n;

    return 0;
}