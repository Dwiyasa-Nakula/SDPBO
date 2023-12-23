#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

//code berasal dari soal 1 namun hanya mengubah int key ke string name

//buat BST Node
struct BSTNode {
    string name;
    BSTNode *left, *right;
    string name;

    BSTNode(const string& n) : name(n), left(nullptr), right(nullptr) {}   
};

//insert node, gabungan primary function dan utility function
BSTNode* insert(BSTNode* root, string name) {
    if (root == nullptr) {
        return new BSTNode(name);
    }

    if (name < root->name) {
        root->left = insert(root->left, name);
    } else if (name > root->name) {
        root->right = insert(root->right, name);
    }

    return root;
};

//Tranversal Inorder, gabungan primary function dan utility function
void levelOrderTraversal(BSTNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<BSTNode*> q;
    q.push(root);

    while (!q.empty()) {
        BSTNode* current = q.front();
        q.pop();
        cout << current->name << " ";

        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
}

int main() {
    BSTNode* root = nullptr;
    string name;

    while(cin >> name) {
        root = insert(root, name);
    }

    levelOrderTraversal(root);
    cout << endl;  

    return 0;
}