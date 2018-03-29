#include <cstdio>
#include <queue>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int a, b, temp;
    deque<vector<int>*> d;
    vector<int> n(200000, -1);
    while (scanf("%d%d", &a, &b) != EOF) {
        if (n[a] == n[b] && n[a] == -1) {
            vector<int>* s = new vector<int>;
            s->push_back(a);
            s->push_back(b);
            d.push_back(s);
            n[a] = n[b] = d.size() - 1;
        }
        else if (n[a] == -1 && n[b] != -1) {
            d[n[b]]->push_back(a);
            n[a] = n[b];
        }
        else if (n[b] == -1 && n[a] != -1) {
            d[n[a]]->push_back(b);
            n[b] = n[a];
        }
        else if (n[a] != -1 && n[b] != -1 && n[a] != n[b]) {
            if (n[a] < n[b]) {
                temp = n[b];
                for (int i = 0; i < d[temp]->size(); i++) {
                    d[n[a]]->push_back(d[temp]->at(i));
                    n[d[temp]->at(i)] = n[a];
                }
            } else {
                temp = n[a];
                for (int i = 0; i < d[temp]->size(); i++) {
                    d[n[b]]->push_back(d[temp]->at(i));
                    n[d[temp]->at(i)] = n[b];
                }
            }
        } else if (n[a] != -1 && n[b] != -1 && n[a] == n[b])
            continue;
        printf("%d %d\n", a, b);
    }
    for (int i = 0; i < d.size(); i++)
        delete d[i];
    return 0;
}
