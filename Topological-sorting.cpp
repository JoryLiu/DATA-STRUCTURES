#include <cstdio>
#include <vector>
using namespace std;

struct node {
    int index;
    vector<int> precursor;
    node(int i) : index(i) {}
};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, index, pre, i, j;
        node* root;
        scanf("%d%d", &n, &m);
        vector<node*> v;
        vector<bool> isFinished(n + 1, false);
        bool hasPre;
        for (int i = 0; i < n; i++)
            v.push_back(new node(i + 1));
        while (m--) {
            scanf("%d%d", &pre, &index);
            v[index - 1]->precursor.push_back(pre);
        }
        while (!v.empty()) {
            for (i = 0; i < v.size(); i++) {
                if (isFinished[v[i]->index]) continue;
                hasPre = false;
                if (!v[i]->precursor.size()) break;
                for (j = 0; j < v[i]->precursor.size(); j++)
                    if (!isFinished[v[i]->precursor.at(j)]) {
                        hasPre = true;
                        break;
                    }
                if (!hasPre) break;
            }
            printf("%d ", v[i]->index);
            isFinished[v[i]->index] = true;
            v.erase(v.begin() + i);
        }
    }
    return 0;
}