#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//buat BST Node
struct BSTNode {
    BSTNode *left, *right;
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
};

//Tranversal Inorder, gabungan primary function dan utility function
void inorderTraversalBST(BSTNode* root) {
    if(root != nullptr) {
        inorderTraversalBST(root->left);
        cout << root->key << " ";
        inorderTraversalBST(root->right);
    }
}

int main() {
    BSTNode* root = nullptr;
    int key;

    //insert node
    for(int i = 0; i <= 100; i++) {
        cin >> key;
        root = insert(root, key);
    }

    //priint transversal inorder
    inorderTraversalBST(root);
    cout << endl;  

    return 0;
}

//saya binggung constraint end input nya bagaimana, jadinya saya langsung kumpulkan dan bisa....