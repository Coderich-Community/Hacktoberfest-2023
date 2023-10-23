#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;

    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalanceFactor(Node* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    void updateHeight(Node* node) {
        if (node != nullptr)
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node* insert(Node* node, int key) {
        if (node == nullptr)
            return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        updateHeight(node);

        int balance = getBalanceFactor(node);

        // Left Heavy
        if (balance > 1) {
            if (key < node->left->key) // Left-Left case
                return rotateRight(node);
            if (key > node->left->key) { // Left-Right case
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }
        // Right Heavy
        if (balance < -1) {
            if (key > node->right->key) // Right-Right case
                return rotateLeft(node);
            if (key < node->right->key) { // Right-Left case
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void display(Node* node, int indent = 0) {
        if (node != nullptr) {
            display(node->right, indent + 4);
            cout << string(indent, ' ') << node->key << endl;
            display(node->left, indent + 4);
        }
    }

    void displayTree() {
        display(root);
    }
};

int main() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    tree.displayTree();

    return 0;
}
