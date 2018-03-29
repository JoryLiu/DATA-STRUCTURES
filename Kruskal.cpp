#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct edge {
    int start, end, length;
    edge(int s, int e, int l) : start(s), end(e), length(l) {}
    bool operator< (const edge& another)const {
        return another.length > length;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, i, j, temp, max, from, to;
        multiset<edge> s;
        multiset<edge>::iterator p;
        vector<vector<int>*> v;
        scanf("%d", &n);
        vector<int> isVisited(n, -1);
        max = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) {
                scanf("%d", &temp);
                if (j > i && temp) s.insert(edge(i, j, temp));
            }
        while (!s.empty()) {
            p = s.begin();
            from = p->start;
            to = p->end;
            if (isVisited[from] == isVisited[to] && isVisited[to] == -1) {
                vector<int>* tmp = new vector<int>;
                tmp->push_back(p->start);
                tmp->push_back(p->end);
                v.push_back(tmp);
                isVisited[from] = v.size() - 1;
                isVisited[to] = v.size() - 1;
                if (max < p->length) max = p->length;
            } else if (isVisited[from] == -1 && isVisited[to] != -1) {
                v[isVisited[to]]->push_back(from);
                isVisited[from] = isVisited[to];
                if (max < p->length) max = p->length;
            } else if (isVisited[from] != -1 && isVisited[to] == -1) {
                v[isVisited[from]]->push_back(to);
                isVisited[to] = isVisited[from];
                if (max < p->length) max = p->length;
            } else if (isVisited[from] != -1 && isVisited[to] != -1 && isVisited[from] != isVisited[to]) {
                temp = isVisited[to];
                for (i = 0; i < v[temp]->size(); i++) {
                    v[isVisited[from]]->push_back(v[temp]->at(i));
                    isVisited[v[temp]->at(i)] = isVisited[from];
                }
                if (max < p->length) max = p->length;
            }
            s.erase(s.begin());
        }
        printf("%d\n", max);
        if (t) printf("\n");
        for (int i = 0; i < v.size(); i++) delete v[i];
    }
    return 0;
}
