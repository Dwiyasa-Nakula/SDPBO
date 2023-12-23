#include <iostream>
using namespace std;

//nyerah

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int data) {
    if (root == nullptr)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getHeight(root->left) - getHeight(root->right);

    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int getMinNodesForHeight(int height) {
    if (height <= 1)
        return height;
    
    return getMinNodesForHeight(height - 1) + getMinNodesForHeight(height - 2) + 1;
}

int main() {
    Node* root = nullptr;

    int H;
    while (true) {
        cin >> H;
        if (H == 0) {
            cout << getMinNodesForHeight(root->height) << endl;
            break;
        } else if (H < 0 || H > 30) {
            cout << "salah bro" << endl;
        } else {
            root = insert(root, H);
        }
    }
    return 0;
}
