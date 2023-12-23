#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to add an element to the linked list
void push(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

// Function to print the linked list in reverse order
void printReverse(struct Node* head) {
    if (head == NULL)
        return;
    printf("%d ", head->data);
    printReverse(head->next);
}

int main() {
    struct Node* head = NULL;
    int input;

    printf("Enter numbers (input 0 to stop):\n");

    while (1) {
        scanf("%d", &input);

        if (input == 0)
            break;
        push(&head, input);
    }

    printf("Reversed linked list:\n");
    printReverse(head);

    return 0;
}
