#include <iostream>

using namespace std;

int main() {
    int n;
    int max = -1;

    while (cin >> n && n != 0) {
        if (max < n) {
            max = n;
        }
    }

    cout << max;

    return 0;
}
