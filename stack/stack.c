#include <stdio.h>

#define ARRAY_SIZE 6
#define STACK_FULL_MSG "stack is already full\n"
#define STACK_PUSH_MSG "push %c into stack\n"
#define STACK_EMPTY_MSG "stack is empty now\n"

typedef struct STACK
{
    int top;
    char array[ARRAY_SIZE];
} Stack;

int isEmpty(Stack stack)
{
    return stack.top == -1;
}

int size(Stack stack)
{
    return stack.top + 1;
}

char getTop(Stack stack)
{
    if (isEmpty(stack))
    {
        printf(STACK_EMPTY_MSG);
        return '#';
    }
    return stack.array[stack.top];
}

void push(Stack *stack, char item)
{
    if (size(*stack) == ARRAY_SIZE - 1)
    {
        printf(STACK_FULL_MSG);
        return;
    }
    stack->array[++stack->top] = item;
    printf(STACK_PUSH_MSG, item);
}

char pop(Stack *stack)
{
    if (isEmpty(*stack))
    {
        printf(STACK_EMPTY_MSG);
        return '#';
    }
    char item = stack->array[stack->top];
    stack->array[stack->top--] = '\0';
    return item;
}

int main()
{
    Stack stack =
        {
            -1,
            {"\0"}};

    push(&stack, 'k');
    push(&stack, 'c');
    push(&stack, 'a');
    push(&stack, 't');
    push(&stack, 's');

    while (!isEmpty(stack))
    {
        printf("%c", pop(&stack));
    }

    return 0;
}