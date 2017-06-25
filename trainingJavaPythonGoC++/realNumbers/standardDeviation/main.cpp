
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    // evaluate upper part as \sum_1^k {x ^ 2} - s * \sum_1_k {x} + n * s ^ 2
    int num;
    int cnt = 0;
    int sum = 0;
    int double_x = 0; // x ^ 2
    double mean;
    double st_dev;

    while (cin >> num && num != 0) {
        ++cnt;
        double_x += num * num;
        sum += num;
    }

    mean = static_cast<double> (sum) / cnt;

    st_dev = sqrt((double_x - 2 * mean * sum + cnt * mean * mean) / (cnt - 1));

    cout << setprecision(11);
    cout << st_dev;

    return 0;
}
