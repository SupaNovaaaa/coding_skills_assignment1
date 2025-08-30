#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define MAX 64  // maximum number of disks

// Stack structure for rods
typedef struct {
    int arr[MAX];
    int top;
    char name;  // Rod name (A, B, C)
} Stack;

// Initialize stack
void init(Stack *s, char name) {
    s->top = -1;
    s->name = name;
}

// Push onto stack
void push(Stack *s, int value) {
    s->arr[++(s->top)] = value;
}

// Pop from stack
int pop(Stack *s) {
    return s->arr[(s->top)--];
}

// Peek top of stack
int peek(Stack *s) {
    return (s->top == -1) ? INT_MAX : s->arr[s->top];
}

// Move disk between two rods
void moveDisk(Stack *src, Stack *dest) {
    int srcDisk = peek(src);
    int destDisk = peek(dest);

    // Case 1: src rod empty -> move from dest to src
    if (srcDisk == INT_MAX) {
        push(src, pop(dest));
        printf("Move disk %d from %c --> %c\n", destDisk, dest->name, src->name);
    }
    // Case 2: dest rod empty -> move from src to dest
    else if (destDisk == INT_MAX) {
        push(dest, pop(src));
        printf("Move disk %d from %c --> %c\n", srcDisk, src->name, dest->name);
    }
    // Case 3: top disk of src > dest -> move from dest to src
    else if (srcDisk > destDisk) {
        push(src, pop(dest));
        printf("Move disk %d from %c --> %c\n", destDisk, dest->name, src->name);
    }
    // Case 4: top disk of dest > src -> move from src to dest
    else {
        push(dest, pop(src));
        printf("Move disk %d from %c --> %c\n", srcDisk, src->name, dest->name);
    }
}

// Iterative Towers of Hanoi
void iterativeHanoi(int n, Stack *src, Stack *aux, Stack *dest) {
    int totalMoves = pow(2, n) - 1;

    // If number of disks is even, swap destination and auxiliary
    if (n % 2 == 0) {
        Stack *temp = dest;
        dest = aux;
        aux = temp;
    }

    // Push all disks to source rod (largest at bottom)
    for (int i = n; i >= 1; i--) {
        push(src, i);
    }

    // Perform moves
    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1)
            moveDisk(src, dest);
        else if (i % 3 == 2)
            moveDisk(src, aux);
        else
            moveDisk(aux, dest);
    }
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    Stack src, aux, dest;
    init(&src, 'A');
    init(&aux, 'B');
    init(&dest, 'C');

    iterativeHanoi(n, &src, &aux, &dest);

    return 0;
}
