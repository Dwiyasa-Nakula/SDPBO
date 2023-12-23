#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int height;
    int data;
    Node* left;
    Node* right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

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

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
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
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalanceFactor(root);

    if (balance > 1) {
        if (data < root->left->data) {
            return rightRotate(root);
        } else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    if (balance < -1) {
        if (data > root->right->data) {
            return leftRotate(root);
        } else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int data) {
    if (root == nullptr)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalanceFactor(root);

    if (balance > 1) {
        if (getBalanceFactor(root->left) >= 0)
            return rightRotate(root);
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1) {
        if (getBalanceFactor(root->right) <= 0)
            return leftRotate(root);
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void freeTree(Node* root) {
    if (root == nullptr)
        return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    int T;
    if (!(cin >> T)) {
        cout << "formatnya salah bro" << endl;
        return 1;
    }

    Node* root = nullptr;

    for (int i = 0; i < T; i++) {
        string action;
        int data;

        if (!(cin >> action >> data)) {
            cout << "formatnya salah bro" << endl;
            freeTree(root);
            return 1;
        }

        if (action == "insert") {
            root = insert(root, data);
        } else if (action == "delete") {
            root = deleteNode(root, data);
        } else {
            cout << "formatnya salah bro" << endl;
            freeTree(root);
            return 1;
        }
    }

    inOrderTraversal(root);
    freeTree(root);
    return 0;
}
