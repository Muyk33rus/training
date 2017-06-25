#include <iostream>

using namespace std;

int main() {
    double num;

    cin >> num;

    cout << num - static_cast<int> (num);

    return 0;
}
