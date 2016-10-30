#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <vector>
#include <cmath>
#include <queue>

template <class T>
class AVLTree;

template <class T>
class Node {
    friend class AVLTree<T>;
public:
    T val;
    int height;
    Node<T>* left;
    Node<T>* right;
    Node(T v, int h = 1, Node<T>* l = NULL, Node<T>* r = NULL) :
        val(v), height(h), left(l), right(r) {
    }
};

template<class T>
class AVLTree {
public:
    AVLTree() : root(NULL) {}
    AVLTree(const std::vector<int>&);
    ~AVLTree();

    Node<T>* insertNode(Node<T>*, T);
    bool searchNode(T);
    bool deleteNode(T);
    void clear();

    Node<T>* getRoot() const;
    int getHeight(Node<T>* root);

    void preOrder(Node<T>*);
    void inOrder(Node<T>*);
    void postOrder(Node<T>*);

private:
    Node<T>* left_left_rotation(Node<T>*);
    Node<T>* left_right_rotation(Node<T>*);
    Node<T>* right_left_rotation(Node<T>*);
    Node<T>* right_right_rotation(Node<T>*);
    Node<T>* root;
};

template<class T>
AVLTree<T>::AVLTree(const std::vector<int>& elements) {
    root = NULL;
    unsigned long size = elements.size();
    for (int i = 0; i < size; i++)
        root = insertNode(root, elements[i]);
}

template<class T>
AVLTree<T>::~AVLTree() {
    clear();
}

inline int max(int a, int b) {
    return a >= b ? a : b;
}

template<class T>
Node<T>* AVLTree<T>::insertNode(Node<T>* root, T element) {
    if (root == NULL)
        root = new Node<T>(element);
    else if (element < root->val) {
        root->left = insertNode(root->left, element);
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        if (getHeight(root->left) - getHeight(root->right) == 2) {
            if (element < root->left->val)
                root = left_left_rotation(root);
            else
                root = left_right_rotation(root);
        }
    }
    else if (element > root->val) {
        root->right = insertNode(root->right, element);
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        if (getHeight(root->right) - getHeight(root->left) == 2) {
            if (element > root->right->val)
                root = right_right_rotation(root);
            else
                root = right_left_rotation(root);
        }
    }
    return root;
}

template<class T>
bool AVLTree<T>::searchNode(T element) {
    Node<T>* temp = root;
    while (temp != NULL) {
        if (temp->val == element)
            return true;
        else if (temp->val > element)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

template<class T>
bool AVLTree<T>::deleteNode(T) {

}

template<class T>
void AVLTree<T>::clear() {
    std::queue<Node<T>*> queue;
    if (root != NULL)
        queue.push(root);
    while (!queue.empty()) {
        Node<T>* temp = queue.front();
        queue.pop();
        if (temp->left != NULL)
            queue.push(temp->left);
        if (temp->right != NULL)
            queue.push(temp->right);
        delete temp;
    }
}

template<class T>
Node<T>* AVLTree<T>::getRoot() const {
    return root;
}

template<class T>
int AVLTree<T>::getHeight(Node<T>* root) {
    return root == NULL ? 0 : root->height;
}

template<class T>
void AVLTree<T>::preOrder(Node<T>* root) {
    if (root != NULL) {
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

template<class T>
void AVLTree<T>::inOrder(Node<T>* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}

template<class T>
void AVLTree<T>::postOrder(Node<T>* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }
}

template<class T>
Node<T>* AVLTree<T>::left_left_rotation(Node<T>* node) {
    Node<T>* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
    return temp;
}

template<class T>
Node<T>* AVLTree<T>::left_right_rotation(Node<T>* node) {
    node->left = right_right_rotation(node->left);
    return left_left_rotation(node);
}

template<class T>
Node<T>* AVLTree<T>::right_left_rotation(Node<T>* node) {
    node->right = left_left_rotation(node->right);
    return right_right_rotation(node);
}

template<class T>
Node<T>* AVLTree<T>::right_right_rotation(Node<T>* node) {
    Node<T>* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
    return temp;
}

#endif AVL_TREE_HPP
