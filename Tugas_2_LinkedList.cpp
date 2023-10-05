#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void push(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void deleteNode(Node*& head, int input) {
    if (head == nullptr) {
        return;
    }
    if (head->data == input) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* current = head;
    while (current->next != nullptr && current->next->data != input) {
        current = current->next;
    }
    if (current->next == nullptr) {
        return;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

void printList(struct Node* head) {
    if (head == nullptr) {
        return;
    }
    printList(head->next);
    cout << head->data << " ";
}

int main() {
    Node* head = nullptr;
    int input;

    cout << "Masukan Linkedlist: ";
    while (1) {
        scanf("%d", &input);
        if (input == 0) {
            break;
        }
        push(&head, input);
    }

    cout << "Linked list: ";
    printList(head);
    cout << endl;

    cout << "Hapus 1 angka dari linkedlist: ";
    cin >> input;
    deleteNode(head, input);
    
    cout << "After deleting an element: ";
    printList(head);
    cout << endl;

    return 0;
}
