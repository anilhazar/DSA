#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node* create_newnode(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = NULL;
    return newnode;
}

void insert(int data, struct node **stack)
{
    struct node *newnode = create_newnode(data);
    newnode->link = *stack;
    *stack = newnode;
}

int delete(struct node **stack)
{
    if(isEmpty(*stack))
    {
        printf("Stack is empty. Nothing to delete.\n");
        return -1;
    }
    int data;
    struct node *temp = *stack;
    data = temp->data;
    *stack = (*stack)->link;
    free(temp);
    printf("The value of the node you deleted: %d\n", data);
    return data;
}

void print_stack(struct node *stack)
{
    struct node *temp = stack;
    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->link;
    }
}

void destroy(struct node **stack)
{
    struct node *temp;
    while(*stack != NULL)
    {
        temp = *stack;
        *stack = (*stack)->link;
        free(temp);
    }
}

int isEmpty(struct node *stack)
{
    return stack == NULL;
}

int stackLength(struct node *stack)
{
    int length = 0;
    while(stack != NULL)
    {
        length++;
        stack = stack->link;
    }
    return length;
}

int peek(struct node *stack)
{
    if(!isEmpty(stack))
    {
        return stack->data;
    }
    else
    {
        printf("Stack is empty.\n");
        return -1;
    }
}

int main()
{
    struct node *top = NULL;
    int data, request = 0;

    do
    {
        printf("Press 1 to add an element to the stack, 2 to delete an element,
               3 to print the stack. Press 4 to delete the entire stack.
               If you want to exit, press 0... ");
               scanf("%d", &request);
               switch(request)
    {
    case 1:
        printf("Enter the data you want to add to the stack.\n");
            scanf(" %d", &data);
            insert(data, &top);
            break;
        case 2:
            delete(&top);
            break;
        case 3:
            print_stack(top);
            break;
        case 4:
            destroy(&top);
            break;
        }
    }
    while(request > 0);

    printf("Is the stack empty? %s\n", isEmpty(top) ? "Yes" : "No");
    printf("Top element of the stack: %d\n", peek(top));
    printf("Number of elements in the stack: %d\n", stackLength(top));

    return 0;
}
