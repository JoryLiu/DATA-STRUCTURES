#include <iostream>
using namespace std;

int main() {
    char c;
    double sum, num, ans;
    while (cin >> c >> sum >> num) {
        ans = 1;
        if (c == 'a' || c == 'A') {
            for (int i = 0; i < num; i++)
                ans *= (sum - i);
        }
        if (c == 'c' || c == 'C') {
            for (int i = 0; i < num; i++)
                ans *= (sum - i) / (i + 1);
        }
        cout << fixed << ans << endl;
    }
}
