#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    int d_x = x1 - x2;
    int d_y = y1 - y2;

    if (d_x != 0 && d_y != 0) {
        if (d_x == d_y || d_x == -d_y) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
    }
    else if (d_x != 0 || d_y != 0) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}