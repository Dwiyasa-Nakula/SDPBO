#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//nyerah

// Struktur Node AVL
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

// Menghitung tinggi pohon AVL
int height(Node* root) {
    if (root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Menyisipkan node baru ke dalam AVL Tree
Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

// Melakukan rotasi kanan
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

// Melakukan rotasi kiri
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

// Menghitung Balance Factor
int getBalance(Node* root) {
    if (root == NULL) return 0;
    return height(root->left) - height(root->right);
}

// Menampilkan hasil secara in-order
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main() {
    int val;
    Node* root = NULL;

    while (cin >> val) {
        if (val == -1) {
            // Akhir input
            break;
        }
        root = insert(root, val);

        // Menyimpan Balance Factor setiap saat
        int balance = getBalance(root);

        // Jika Balance Factor terlalu besar (lebih dari 1 atau kurang dari -1),
        // lakukan rotasi untuk menjaga keseimbangan
        if (balance > 1 && val < root->left->key)
            root = rightRotate(root);
        else if (balance < -1 && val > root->right->key)
            root = leftRotate(root);
        else if (balance > 1 && val > root->left->key) {
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        } else if (balance < -1 && val < root->right->key) {
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }
    }

    inOrder(root);
    cout << endl;

    return 0;
}
