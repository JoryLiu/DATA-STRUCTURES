#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <vector>
#include <cmath>

template<typename T>
class AVLTree {
public:
    struct Node {
        T val;
        int height;
        Node* left;
        Node* right;
        Node(T v, int h = 1, Node* l = NULL, Node* r = NULL) :
            val(v), height(h), left(l), right(r) {
        }
    };
    AVLTree();
    AVLTree(const std::vector<int>&);
    ~AVLTree();

    Node* insertNode(Node*, T);
    bool searchNode(T);
    bool deleteNode(T);
    void clear();

    Node* getRoot() const;
    int getHeight(Node* root);

    void preOrder(Node*);
    void inOrder(Node*);
    void postOrder(Node*);

private:
    Node* left_left_ratation(Node*);
    Node* left_right_ratation(Node*);
    Node* right_left_ratation(Node*);
    Node* right_right_ratation(Node*);
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
    for (int i = 0; i < size; i++)
        root = insertNode(root, elements[i]);
}

template<typename T>
AVLTree<T>::~AVLTree() {
    clear();
}

inline int max(int a, int b) {
    return a >= b ? a : b;
}

template<typename T>
Node<T>* AVLTree<T>::insertNode(Node<T>* root, T element) {
    if (root == NULL) {
        root = new Node(element);
    }
    else if (element < root->val) {
        root = insertNode(root->left, element);
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        if (getHeight(temp->left) - getHeight(temp->right) == 2) {
            if (element < temp->left->val)
                root = left_left_rotation(root);
            else
                root = left_right_rotation(root);
        }
    }
    else if (element > root->val) {
        root = insertNode(root->right, element);
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        if (getHeight(temp->right) - getHeight(temp->left) == 2) {
            if (element > temp->right->val)
                root = right_right_rotation(root);
            else
                root = right_left_rotation(root);
        }
    }

}

template<typename T>
bool AVLTree<T>::searchNode(T element) {
    Node* temp = root;
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

template<typename T>
bool AVLTree<T>::deleteNode(T) {

}

template<typename T>
void AVLTree<T>::clear() {
    std::queue<Node*> queue;
    if (root != NULL)
        queue.push(root);
    while (!queue.empty()) {
        Node* temp = queue.front();
        queue.pop();
        if (temp->left != NULL)
            queue.push(temp->left);
        if (temp->right != NULL)
            queue.push(temp->right);
        delete temp;
    }
}

template<typename T>
Node<T>* AVLTree<T>::getRoot() const {
    return root;
}

template<typename T>
int AVLTree<T>::getHeight(Node* root) {
    return root == NULL ? 0 : root->height;
}

template<typename T>
void AVLTree<T>::preOrder(Node* root) {
    if (root != NULL) {
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

template<typename T>
void AVLTree<T>::inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}

template<typename T>
void AVLTree<T>::postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }
}

template<typename T>
AVLTree<T>::Node<T>* AVLTree<T>::left_left_ratation(Node* node) {
    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
    return temp;
}

template<typename T>
AVLTree<T>::Node* AVLTree<T>::left_right_ratation(Node* node) {
    node->left = right_right_rotation(node->left);
    return left_left_ratation(node);
}

template<typename T>
AVLTree<T>::Node* AVLTree<T>::right_left_ratation(Node* node) {
    node->right = left_left_rotation(node->right);
    return right_right_ratation(node);
}

template<typename T>
AVLTree<T>::Node* AVLTree<T>::right_right_ratation(Node* node) {
    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
    return temp;
}

#endif AVL_TREE_HPP
