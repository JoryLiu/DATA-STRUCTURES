#include <iostream>
#include <queue>
#include <list>
using namespace std;
 
int main() {
    int c;
    cin >> c;
    while (c--) {
        list<int> q;
        int n, m, i, temp, flag, time = 0, min, max;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            q.push_back(temp);
        }
        list<int>::iterator p;
        while (q.size() > 0) {
            max = q.front();
            for (p = q.begin(); p != q.end(); p++) {
                if (max < *p) max = *p;
            }
            if (max > q.front()) {
                q.push_back(q.front());
                if (m == 0) m += q.size() - 1;
            }
            if (max == q.front()) time++;
            q.pop_front();
            m--;
            if (m == -1) break;
        }
        cout << time << endl;
    }
}
