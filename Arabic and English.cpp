#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    deque<string> left, right;
    string english, temp;
    int n, num;
    bool flag = 0;
    cin >> n;
    while (n--) {
        cin >> num;
        flag = false;
        for (int i = 0; i < num; i++) {
            cin >> temp;
            if (temp[0] != '#') {
                english = temp;
                flag = true;
            }
            else {
                if (!flag) left.push_back(temp);
                if (flag) right.push_back(temp);
            }
        }
        for (int i = 0; i < right.size(); i++)
            cout << right[i] << " ";
        if (english.size()) cout << english << " ";
        for (int i = 0; i < left.size(); i++) {
            if (i == left.size() - 1) cout << left[i];
            else cout << left[i] << " ";
        }
        cout << endl;
        left.clear();
        right.clear();
        english.clear();
    }
    return 0;
}
