#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <cstdio>
using namespace std;

int main() {
    /*freopen("twostack.in", "r", stdin);
    freopen("twostack.out", "w", stdout);*/
    int n, temp, counter;
    queue<int> q;
    stack<int> s1, s2;
    string ans;
    bool flag;
    while (cin >> n) {
        ans.clear();
        while (!s1.empty()) s1.pop();
        while (!s2.empty()) s2.pop();
        while (!q.empty()) q.pop();
        counter = 1;
        flag = true;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            q.push(temp);
        }
        while (counter <= n) {
            if (!s1.empty() && s1.top() == counter) {
                s1.pop();
                counter++;
                ans += "b";
                continue;
            }
            if (!s2.empty() && s2.top() == counter) {
                s2.pop();
                counter++;
                ans += "d";
                continue;
            }
            if (s1.empty() || (!s1.empty() && q.front() < s1.top())) {
                temp = q.front();
                q.pop();
                s1.push(temp);
                ans += "a";
                continue;
            }
            else if (s2.empty() || (!s2.empty() && q.front() < s2.top())) {
                temp = q.front();
                q.pop();
                s2.push(temp);
                ans += "c";
                continue;
            }
            else {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int i = 0; i < ans.size(); i++) {
                if (i == 0) cout << ans[0];
                if (i > 0) cout << " " << ans[i];
            }
            cout << endl;
        }
        else {
            cout << "0" << endl;
        }
    }
    return 0;
}
