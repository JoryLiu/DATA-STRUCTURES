#include <cstdio>
#include <vector>
#include <deque>
#include <limits>
using namespace std;

struct node {
    int data, level;
    node *left, *right;
    node(int d, node* l = NULL, node* r = NULL) : data(d), left(l), right(r) { level = 0; }
};

node* build(int* pre, int* in, int n) {
    if (!n) return NULL;
    if (n == 1) return new node(pre[0]);
    int i, head = pre[0];
    for (i = 0; i < n; i++)
        if (in[i] == head)
            break;
    node* result = new node(head, build(pre + 1, in, i), build(pre + i + 1, in + i + 1, n - i - 1));
    if (result->left != NULL && result->right != NULL)
        result->level = result->left->level > result->right->level ? result->left->level + 1 : result->right->level + 1;
    else if (result->left != NULL)
        result->level = result->left->level + 1;
    else if (result->right != NULL)
        result->level = result->right->level + 1;
    return result;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int *pre, *in;
        pre = new int[n];
        in = new int[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &pre[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &in[i]);
        node* root = build(pre, in, n);
        printf("%d\n", root->level);
        delete[]pre;
        delete[]in;
    }
    return 0;
}
