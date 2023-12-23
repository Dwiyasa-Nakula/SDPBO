#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct BSTNode {
    char data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(char c) : data(c), left(nullptr), right(nullptr) {}
};

BSTNode* insert(BSTNode* root, char c) {
    if (root == nullptr) {
        return new BSTNode(c);
    }

    if (c < root->data) {
        root->left = insert(root->left, c);
    } else {
        root->right = insert(root->right, c);
    }

    return root;
}

void __inorder(BSTNode *root) {
    if (root) {
        __inorder(root->left);
        printf("%d ", root->data);
        __inorder(root->right);
    }
}

void traverseInorder(BSTNode* root) {
    __inorder(root);
}

int main() {
    string input;
    getline(cin, input);

    BSTNode* root = nullptr;

    for (char c : input) {
        if (c != ' ') {  // Ignore spaces
            root = insert(root, c);
        }
    }

    traverseInorder(root);
    cout << endl;

    return 0;
}