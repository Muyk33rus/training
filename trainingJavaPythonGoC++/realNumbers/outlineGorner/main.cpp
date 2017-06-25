
#include <iostream>

using namespace std;

int main() {
    int n;
    double x;
    double res = 0;
    double coef;

    cin >> n >> x;

    while (n--) {
        cin >> coef;
        res += coef;
        res *= x;
    }

    cin >> coef;
    res += coef;
    cout << res;

    return 0;
}