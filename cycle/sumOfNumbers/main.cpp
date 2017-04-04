#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int n;

    while (cin >> n && n != 0) {
        sum += n;
    }

    cout << sum;

    return 0;
}
