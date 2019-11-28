#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a stack
struct Stack
{
    int top;
    unsigned capacity;
    char *array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity);
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{   return stack->top == stack->capacity - 1; }

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{   return stack->top == -1;  }

// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, char *item)
{
    if (isFull(stack)) {
        printf("Stack is Full! Number of %s don't add.",item);
        return;
    }
    stack->array[++stack->top] = item;
    printf("%s pushed to stack\n", item);
}

// Function to remove an item from stack.  It decreases top by 1
char pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
// Driver program to test above functions
int main()
{
    struct Stack* stack = createStack(8);

    push(stack, "Ali");
    push(stack, "20");
    push(stack, "10");
    push(stack, "20");
    push(stack, "10");
    push(stack, "20");

    //printf("\n%s popped from stack\n", pop(stack));
    push(stack, "10");
    push(stack, "20");

    return 0;
}
