#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct node {
    int index;
    vector<int> successor;
    node(int i) : index(i) {}
};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, index, pre, i, j;
        scanf("%d%d", &n, &m);
        vector<node*> v;
        vector<int> precursor(200000, 0);
        for (int i = 0; i < n; i++)
            v.push_back(new node(i + 1));
        while (m--) {
            scanf("%d%d", &pre, &index);
            v[pre - 1]->successor.push_back(index);
            precursor[index]++;
        }
        set<int> s;
        for (i = 1; i <= n; i++)
            if (!precursor[i])
                s.insert(i);
        while (!s.empty()) {
            index = *s.begin();
            printf("%d ", index);
            for (j = 0; j < v[index - 1]->successor.size(); j++) {
                precursor[v[index - 1]->successor.at(j)]--;
                if (precursor[v[index - 1]->successor.at(j)] == 0)
                    s.insert(v[index - 1]->successor.at(j));
            }
            s.erase(index);
        }
        for (i = 0; i < v.size(); i++) delete v[i];
        v.clear();
        printf("\n");
    }
    return 0;
}
