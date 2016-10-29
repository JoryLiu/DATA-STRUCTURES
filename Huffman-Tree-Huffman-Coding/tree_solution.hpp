#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
 
namespace MP {
    struct TreeNode {
        int weight;
        int id;
        string code;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int w, int i, string c = "",
            TreeNode* l = NULL, TreeNode* r = NULL) :
            weight(w), id(i), code(c), left(l), right(r) {}
    };
 
    struct NodeCmp {
        int depth(const TreeNode*  root) {
            if (root == NULL) return 0;
            if (root != NULL) {
                /*return (depth(root->left) > depth(root->right) ?
                    depth(root->left) : depth(root->right)) + 1;*/
                return depth(root->left) + depth(root->right) + 1;
            }
        }
        bool operator()(TreeNode *na, TreeNode *nb) {
            if (na->weight != nb->weight)
                return na->weight > nb->weight;
            if (na->weight == nb->weight) {
                int max1, max2;
                max1 = depth(na);
                max2 = depth(nb);
                if (max1 == max2) {
                    if (max1 == 1) {
                        if (na->id > nb->id) return true;
                        if (na->id < nb->id) return false;
                    }
                    if (na->id > nb->id) return false;
                    if (na->id < nb->id) return true;
                }
                return max1 > max2;
            }
        }
    };
    struct NodeCmp2 {
        bool operator()(TreeNode *na, TreeNode *nb) {
            if (na->weight != nb->weight)
                return na->weight > nb->weight;
            if (na->weight == nb->weight)
                return na->id > nb->id;
        }
    };
 
    class MaxPath {
    private:
        int max;
    public:
        MaxPath() : max(0) {}
        explicit MaxPath(int MAX_INIT) : max(MAX_INIT) {}
        int findMaxPath(TreeNode *root) {
            if (root == NULL) return 0;
            if (root != NULL) {
                int temp = findMaxPath(root->left) > findMaxPath(root->right) ?
                    findMaxPath(root->left) : findMaxPath(root->right);
                return root->weight + temp;
            }
        }
    };
 
}  // namespace MP
 
namespace HFM {
 
    class HuffmanCode {
    private:
        MP::TreeNode* root;
        string ot;
    public:
        explicit HuffmanCode(const string & str) {
            root = NULL;
            string::iterator index;
            ot = str;
            for (index = ot.begin(); index != ot.end(); index++) {
                if (*index == ' ') ot.erase(index);
            }
            int alphabet[26] = { 0 };
            for (int i = 0; i < ot.size(); i++)
                alphabet[ot[i] - 'a']++;
            priority_queue<MP::TreeNode*,
                vector<MP::TreeNode*>, MP::NodeCmp> q;
            for (int i = 0; i < 26; i++) {
                if (alphabet[i] > 0) {
                    MP::TreeNode *temp = new MP::TreeNode(alphabet[i], i);
                    q.push(temp);
                }
            }
            MP::TreeNode *l, *r;
            while (q.size() > 1) {
                l = q.top();
                q.pop();
                r = q.top();
                q.pop();
                q.push(new MP::TreeNode(l->weight + r->weight,
                    -(abs(l->id) + abs(r->id)),
                    "", l, r));
            }
            root = q.top();
        }
        HuffmanCode(int w[], int n) {
            root = NULL;
            ot = "";
            priority_queue<MP::TreeNode*,
                vector<MP::TreeNode*>, MP::NodeCmp> q;
            for (int i = 0; i < n; i++) {
                MP::TreeNode *temp = new MP::TreeNode(w[i], i);
                q.push(temp);
            }
            MP::TreeNode *l, *r;
            while (q.size() > 1) {
                l = q.top();
                q.pop();
                r = q.top();
                q.pop();
                q.push(new MP::TreeNode(l->weight + r->weight,
                    -(abs(l->id) + abs(r->id)), "", l, r));
            }
            root = q.top();
        }
        void clear(MP::TreeNode* p) {
            if (p != NULL) {
                clear(p->left);
                clear(p->right);
                delete p;
            }
        }
        ~HuffmanCode() {
            clear(root);
        }
        void DisplayCode() {
            priority_queue<MP::TreeNode*,
                vector<MP::TreeNode*>, MP::NodeCmp2> q;
            queue<MP::TreeNode*> q2;
            q2.push(root);
            MP::TreeNode* temp;
            int length = 0;
            while (!q2.empty()) {
                temp = q2.front();
                if (temp->left != NULL) {
                    temp->left->code = temp->code + "1";
                    q2.push(temp->left);
                }
                if (temp->right != NULL) {
                    temp->right->code = temp->code + "0";
                    q2.push(temp->right);
                }
                if (temp->id > -1) q.push(temp);
                q2.pop();
            }
            if (ot == "") {
                while (!q.empty()) {
                    temp = q.top();
                    length += temp->weight * temp->code.size();
                    cout << "Weight = " << temp->weight;
                    cout << "; Code = " << temp->code << endl;
                    q.pop();
                }
                cout << "Huffman's codeLength = " << length << endl;
            } else {
                map<int, string> m;
                while (!q.empty()) {
                    temp = q.top();
                    m.insert(make_pair(temp->id, temp->code));
                    length += temp->weight * temp->code.size();
                    printf("(%c) ", temp->id + 'a');
                    cout << "Weight = " << temp->weight;
                    cout << "; Code = " << temp->code << endl;
                    q.pop();
                }
                cout << "Huffman's codeLength = " << length << endl;
                cout << "Origin Text: " << ot << endl;
                cout << "Huffman's Code: ";
                map<int, string>::iterator index;
                for (int i = 0; i < ot.size(); i++) {
                    index = m.find(ot[i] - 'a');
                    cout << index->second;
                }
                cout << endl;
            }
        }
    };
 
}  // namespace HFM
