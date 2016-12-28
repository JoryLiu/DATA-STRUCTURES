#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;

typedef pair<int, int> PAIR;
struct cmpByValue {
    bool operator()(const PAIR& a, const PAIR& b) {
        return a.second < b.second;
    }
};

struct entry {
    int id;
    vector<int> item;
    entry(int i, vector<int> it) : id(i), item(it) {}
};

struct cmp {
    int m;
    vector<PAIR> priority;
    cmp(int m_, vector<PAIR> p) : m(m_), priority(p) {}
    bool operator()(const entry& a, const entry& b) {
        for (int i = 0; i < m; i++) {
            if (a.item[priority[i].first] < b.item[priority[i].first])
                return true;
            if (a.item[priority[i].first] > b.item[priority[i].first])
                return false;
        }
        return a.id < b.id;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, temp, q;
        vector<int> num;
        vector<entry> db;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            num.clear();
            for (int j = 0; j < m; j++) {
                scanf("%d", &temp);
                num.push_back(temp);
            }
            db.push_back(entry(i, num));
        }
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            vector<PAIR> priority;
            for (int j = 0; j < m; j++) {
                scanf("%d", &temp);
                priority.push_back(make_pair(j, temp));
            }
            sort(priority.begin(), priority.end(), cmpByValue());
            cmp dbCmp(m, priority);
            sort(db.begin(), db.end(), dbCmp);
            for (int j = 0; j < n; j++) {
                if (!j) printf("%d", db[j].id);
                else printf(" %d", db[j].id);
            }
            printf("\n");
        }
    }
    return 0;
}
