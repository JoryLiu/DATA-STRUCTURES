#include <cstdio>
#include <set>
#include <deque>
using namespace std;

int main() {
    int a, b;
    deque<set<int>*>::iterator ia, ib;
    deque<set<int>*> d;
    while (scanf("%d%d", &a, &b) != EOF) {
        for (ia = d.begin(); ia != d.end(); ia++)
            if ((*ia)->find(a) != (*ia)->end())
                break;
        for (ib = d.begin(); ib != d.end(); ib++)
            if ((*ib)->find(b) != (*ib)->end())
                break;
        if (ia == ib && ia == d.end()) {
            set<int>* s = new set<int>;
            s->insert(a);
            s->insert(b);
            d.push_back(s);
        } else if (ia == d.end() && ib != d.end())
            (*ib)->insert(a);
        else if (ib == d.end() && ia != d.end())
            (*ia)->insert(b);
        else if (ia != d.end() && ib != d.end() && ia != ib) {
            if (ia < ib) {
                (*ia)->insert((*ib)->begin(), (*ib)->end());
                delete(*ib);
                d.erase(ib);
            } else {
                (*ib)->insert((*ia)->begin(), (*ia)->end());
                delete(*ia);
                d.erase(ia);
            }
        } else if (ia != d.end() && ib != d.end() && ia == ib)
            continue;
        printf("%d %d\n", a, b);
    }
    for (int i = 0; i < d.size(); i++)
        delete d[i];
    return 0;
}
