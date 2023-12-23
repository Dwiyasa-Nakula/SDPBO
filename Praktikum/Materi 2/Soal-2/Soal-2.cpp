#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//code berasal dari soal 1 namun hanya mengubah transversal in order menjadi preorder

//buat BST Node
struct BSTNode {
    BSTNode* left;
    BSTNode* right;
    int key;

    BSTNode(int val) : key(val), left(nullptr), right(nullptr) {}
};

//insert node, gabungan primary function dan utility function
BSTNode* insert(BSTNode* root, int key) {
    if (root == nullptr) {
        return new BSTNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

//traversePreorder tanpa childern atau leaf note
void traversePreorder(BSTNode* root) {
    if (root != nullptr) {
        if (root->left == nullptr && root->right == nullptr) { // Leaf node
            cout << root->key << " ";
        }

        traversePreorder(root->left);
        traversePreorder(root->right);
    }
}

int main() {
    BSTNode* root = nullptr;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        root = insert(root, key);

        if (i >= 1000) {
            cout << "Bang udah bang." << endl;
            return 0;
        }
    }

    traversePreorder(root);
    cout << endl;

    return 0;
}