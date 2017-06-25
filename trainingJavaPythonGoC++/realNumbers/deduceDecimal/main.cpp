#include <iostream>

using namespace std;

int main() {
    double num;

    cin >> num;

    double frac = num - static_cast<int> (num);

    cout << static_cast<int> (frac * 10);

    return 0;
}