#include <iostream>
using namespace std;

// membuat note untuk linkedlist
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Insert a node at the beginning of the list
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = createNode(newData);
    newNode->next = head;
    head = newNode;
}

// Insert a node after a given node
void insertAfter(Node* prevNode, int newData) {
    if (prevNode == nullptr) {
        cout << "Error: Previous node cannot be NULL" << endl;
        return;
    }
    Node* newNode = createNode(newData);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Insert a node at the end of the list
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = createNode(newData);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// Delete a node with a given value
void deleteNode(Node*& head, int key) {
    if (head == nullptr) {
        return;
    }
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* current = head;
    while (current->next != nullptr && current->next->data != key) {
        current = current->next;
    }
    if (current->next == nullptr) {
        return;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

// Search for a value in the list
bool searchNode(const Node* head, int key) {
    const Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Sort the linked list (bubble sort)
void sortLinkedList(Node*& head) {
    if (head == nullptr) {
        return;
    }
    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// Print the linked list
void printList(const Node* head) {
    const Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 1);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 3);
    insertAtEnd(head, 4);
    insertAfter(head->next, 5);

    cout << "Linked list: ";
    printList(head);

    cout << "After deleting an element: ";
    deleteNode(head, 3);
    printList(head);

    int item_to_find = 3;
    if (searchNode(head, item_to_find)) {
        cout << item_to_find << " is found" << endl;
    } else {
        cout << item_to_find << " is not found" << endl;
    }

    sortLinkedList(head);
    cout << "Sorted List: ";
    printList(head);

    return 0;
}
