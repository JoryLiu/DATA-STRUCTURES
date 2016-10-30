#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <vector>
#include <cmath>

template<typename T>
class AVLTree {
  public:
    typedef struct Node {
        int val;
        int height;
        Node* left;
        Node* right;
        Node(int v, int h = 1, Node* l = NULL, Node* r = NULL) :
            val(v), height(h), left(l), right(r) {
        }
    };
    AVLTree();
    AVLTree(const std::vector<int>&);
    ~AVLTree();

    bool insertNode(int);
    bool searchNode(int);
    bool deleteNode(int);
    void clear();

    Node* getRoot() const;
    int getHeight(Node* root);

    void preOrder(void(*visit)(T&), Node*);
    void inOrder(void(*visit)(T&), Node*);
    void postOrder(void(*visit)(T&), Node*);

  private:
    Node* root;
};

template<typename T>
AVLTree<T>::AVLTree() {
    root = NULL;
}

template<typename T>
AVLTree<T>::AVLTree(const std::vector<int>& elements) {
    root = NULL;
    unsigned long size = elements.size();
    for (int i = 0; i < size; i++) {
        insertNode(elements[i]);
    }
}

template<typename T>
AVLTree<T>::~AVLTree() {
    clear();
}

inline int max(int a, int b) {
    return a >= b ? a : b;
}

template<typename T>
bool AVLTree<T>::insertNode(int) {
    Node *temp = root;
    if (temp == NULL) {
        temp = new Node(element);
        root = temp;
        return true;
    }
    else {
        while (temp != NULL) {
            if (temp->val == element) {
                return false;
            }
            else if (temp->val > element) {
                if (temp->left == NULL) {
                    temp->left = new Node(element);
                    temp->height = max(temp->left->height, temp->right->height) + 1;
                    if (temp->left->height - temp->right->height == 2) {
                        if (element < temp->left->val)
                            leftLeftRotation(temp);
                        else
                            leftRightRotation(temp);
                    }
                    return true;
                }
                else {
                    temp = temp->left;
                }
            }
            else {
                if (temp->right == NULL) {
                    temp->right = new Node(element);
                    temp->height = max(temp->left->height, temp->right->height) + 1;
                    if (temp->right->height - temp->left->height == 2) {
                        if (element > temp->right->val)
                            rightRightRotation(temp);
                        else
                            rightLeftRotation(temp);
                    }
                    return true;
                }
                else {
                    temp = temp->right;
                }
            }
        }
    }
    return false;
}

template<typename T>
bool AVLTree<T>::searchNode(int) {
    Node *temp = root;
    while (temp != NULL) {
        if (temp->val == element) {
            return true;
        }
        else if (temp->val > element) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }
    return false;
}

template<typename T>
bool AVLTree<T>::deleteNode(int) {

}

template<typename T>
void AVLTree<T>::clear() {
    std::queue<Node*> queue;
    if (root != NULL) {
        queue.push(root);
    }
    while (!queue.empty()) {
        Node * temp = queue.front();
        queue.pop();
        if (temp->left != NULL)
            queue.push(temp->left);
        if (temp->right != NULL)
            queue.push(temp->right);
        delete temp;
    }
}

template<typename T>
Node* AVLTree<T>::getRoot() const {
    return root;
}

template<typename T>
int AVLTree<T>::getHeight(Node* root) {
    return root == NULL ? 0 : root->height;
}

template<typename T>
void AVLTree<T>::preOrder(void(*visit)(T&), Node*) {
    if (root != NULL) {
        visit(root->val);
        preOrder(visit, root->left);
        preOrder(visit, root->right);
    }
}

template<typename T>
void AVLTree<T>::inOrder(void(*visit)(T&), Node*) {
    if (root != NULL) {
        inOrder(visit, root->left);
        visit(root->val);
        inOrder(visit, root->right);
    }
}

template<typename T>
void AVLTree<T>::postOrder(void(*visit)(T&), Node*) {
    if (root != NULL) {
        postOrder(visit, root->left);
        postOrder(visit, root->right);
        visit(root->val);
    }
}

#endif AVL_TREE_HPP
