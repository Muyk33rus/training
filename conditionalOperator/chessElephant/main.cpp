#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    if ((x1 - x2 > 0 || x1 - x2 < 0 || x1 - x2 == 0)) {
        if (y1 - y2 == x1 - x2 || y1 - y2 == -(x1 - x2)) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
    }
    else {
        cout << "NO";
    }
}