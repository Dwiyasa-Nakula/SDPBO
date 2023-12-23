#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//pakai stack
struct Stack {
    int data[1000];
    int top;
};

//inisialisasi stack
void initialize(struct Stack *s) {
    s->top = -1;
}

//mengisi stack
void push(struct Stack *s, int value) {
    s->data[++(s->top)] = value;
}

//menghapus elemen dari stack
int pop(struct Stack *s) {
    return s->data[(s->top)--];
}

//mengurutkan bilangan secara ascending
void urut(int arr[], int n) {
    struct Stack s1, s2; 
    initialize(&s1); //void initialize
    initialize(&s2); //void initialize

    // Masukkan ke stack s1
    for (int i = 0; i < n; i++) {
        push(&s1, arr[i]);
    }

    // Urutkan yang distack s1 ke stack s2
    while (s1.top != -1) {
        int temp = pop(&s1);
        while (s2.top != -1 && s2.data[s2.top] < temp) {
            push(&s1, pop(&s2));
        }
        push(&s2, temp);
    }

    // Keluarkan dari stack s2 ke arr hasil
    for (int i = 0; i < n; i++) {
        arr[i] = pop(&s2);
    }
}

int main() {
    //declarasi variable
    int arr[1000];
    int n = 0;

    while (1) { //baca input sampai done
        char input[10]; //pakai arr agar bisa ambil kata done
        scanf("%s", input); //baca semua input
        if (strcmp(input, "done") == 0) { //lalu compare string dengan done jika sama break
            break;
        }
        arr[n++] = atoi(input); //masukan ke arr dari string ke integer
    }

    urut(arr, n); //masukan void urutkan
    for (int i = 0; i < n; i++) { //print hasil urutkan
        printf("%d ", arr[i]);
    }
    return 0;
}
