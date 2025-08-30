#include <stdio.h>
#define MAX 100   // maximum size of stack

// Stack structure
typedef struct {
    int arr[MAX];  // array to hold stack elements
    int top;       // index of the top element
} Stack;

// Initialize stack
void init(Stack *s) {
    s->top = -1;  // empty stack
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push element onto stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        s->arr[++(s->top)] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Pop element from stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    } else {
        return s->arr[(s->top)--];
    }
}

// Peek (see top element without removing it)
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return s->arr[s->top];
    }
}

// Display stack elements
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

// -------- MAIN --------
int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    display(&s);

    printf("Top element is %d\n", peek(&s));

    printf("%d popped from stack\n", pop(&s));
    printf("%d popped from stack\n", pop(&s));

    display(&s);

    return 0;
}
