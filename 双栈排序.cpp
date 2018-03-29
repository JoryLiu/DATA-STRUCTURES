#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
deque<int> q;
stack<int> s1, s2;
queue<int> que;
string ans;
int n, counter;
int check[2000];
bool flag[2000];
bool path[2000][2000];

void makeChoice() {
    int temp;
    while ((!s1.empty() && s1.top() == counter) || (!s2.empty() && s2.top() == counter)) {
        if (!s1.empty() && s1.top() == counter) {
            s1.pop();
            counter++;
            ans += "b";
        }
        if (!s2.empty() && s2.top() == counter) {
            s2.pop();
            counter++;
            ans += "d";
        }
    }
    if (counter > n) return;
    if (check[q.front()] == 1) {
        temp = q.front();
        q.pop_front();
        s1.push(temp);
        ans += "a";
        makeChoice();
    }
    else if (check[q.front()] == 2) {
        temp = q.front();
        q.pop_front();
        s2.push(temp);
        ans += "c";
        makeChoice();
    }
}

bool bfs() {
    int count = 0;
    while (count < n) {
        for (int i = 0; i < n; i++)
            if (check[q[i]] == 0) {
                que.push(q[i]);
                check[q[i]] = 1;
                count++;
                break;
            }
        while (!que.empty()) {
            for (int i = 1; i <= n; i++)
                if (path[que.front()][i]) {
                    if (check[i]) {
                        if (check[que.front()] + check[i] != 3) return false;
                    }
                    else {
                        check[i] = 3 - check[que.front()];
                        que.push(i);
                        count++;
                    }
                }
            que.pop();
        }
    }
    return true;
}

int main() {
    /*freopen("twostack.in", "r", stdin);
    freopen("twostack.out", "w", stdout);*/
    int temp;
    while (cin >> n) {
        for (int i = 1; i < n + 1; i++) {
            check[i] = 0;
            flag[i] = false;
        }
        ans.clear();
        for (int i = 0; i < n + 1; i++)
            for (int j = 0; j < n + 1; j++)
                path[i][j] = 0;
        while (!s1.empty()) s1.pop();
        while (!s2.empty()) s2.pop();
        while (!que.empty()) que.pop();
        while (!q.empty()) q.pop_back();
        for (int i = 0; i < n; i++) {
            cin >> temp;
            q.push_back(temp);
        }
        counter = 1;
        for (int i = 0; i < n; i++)
            for (int j = n - 1; j > i; j--) {
                if (q[j] < q[i]) {
                    for (int k = i; k < j; k++)
                        if (q[k] > q[i]) {
                            path[q[i]][q[k]] = 1;
                            path[q[k]][q[i]] = 1;
                        }
                }
            }
        if (bfs()) makeChoice();
        if (!ans.empty()) {
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
