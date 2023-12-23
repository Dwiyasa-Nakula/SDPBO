#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//pakai linkedlist
struct Node {
    int data;
    struct Node* next;
};

//masukan ke linkedlist
void push(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

//menghitung jarak perjalanan
int hitungJarak(struct Node* head){
    int panjangJarak = 0;
    while(head != 0){
    panjangJarak++;
    head = head->next;    
    }
    return panjangJarak;
}

int main() {
    //deklarasi variable
    struct Node* head = NULL;
    int input;
    
    //membaca input sampai 0
    while (1) {
        scanf("%d", &input);
        if (input == 0) {
            break;
        }
        push(&head, input);
    }
    int panjangJarak = hitungJarak(head);
    printf("%d ", panjangJarak); 
    return 0;
}
