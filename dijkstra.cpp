#include <cstdio>
#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <string>
using namespace std;

#define MAX 1000

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        map<string, int> m;
        string start, end;
        int n, length, counter = 0, s, e;
        vector<vector<int>> matrix(MAX, vector<int>(MAX, numeric_limits<int>::max() >> 1)); // in case of overflow
        for (int i = 0; i < MAX; i++) matrix[i][i] = 0;
        scanf("%d", &n);
        while (n--) {
            cin >> start >> end;
            scanf("%d", &length);
            if (start != end) {
                if (m.find(start) == m.end())
                    m.insert(make_pair(start, counter++));
                if (m.find(end) == m.end())
                    m.insert(make_pair(end, counter++));
                s = m[start];
                e = m[end];
                matrix[s][e] = matrix[e][s] = length;
            }
        }
        cin >> start >> end;
        if (start == end)
            printf("0\n");
        else if (m.find(start) == m.end() || m.find(end) == m.end())
            printf("-1\n");
        else {
            s = m[start];
            e = m[end];
            vector<bool> isVisited(m.size(), false);
            vector<int> distance(m.size(), numeric_limits<int>::max() >> 1);
            map<string, int>::iterator p;
            distance[s] = 0;
            for (int i = 0; i < m.size(); i++) {
                int min = numeric_limits<int>::max();
                isVisited[s] = true;
                for (p = m.begin(); p != m.end(); p++)
                    if (distance[p->second] > distance[s] + matrix[s][p->second])
                        distance[p->second] = distance[s] + matrix[s][p->second];
                for (p = m.begin(); p != m.end(); p++)
                    if (!isVisited[p->second] && distance[p->second] < min) {
                        min = distance[p->second];
                        s = p->second;
                    }
                if (min == numeric_limits<int>::max()) break;
            }
            if (distance[e] != numeric_limits<int>::max() >> 1) printf("%d\n", distance[e]);
            else printf("-1\n");
        }
    }
    return 0;
}
