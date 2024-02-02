#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *next;
};

struct node* createNode(int key)
{
    struct node *x;
    x=(struct node*)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Unable to allocate heap \n");
        exit(1);
    }
    x->next=NULL;
    x->key=key;
    return x;
}

void addListHead(struct node **header, int key)
{
    struct node *temp = createNode(key);
    temp->next=*header;
    *header=temp;
}

void addListEnd(struct node **header, int key)
{
    struct node *toBeAdded = createNode(key);
    struct node *temp=*header;
    if(*header == NULL)
    {
        *header=toBeAdded;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=toBeAdded;
    }
}

void printList(struct node *header)
{
    if (header == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        while (header != NULL)
        {
            printf("%4d ", header->key);
            header = header->next;
        }
    }
    printf("\n");
}

void printListRecursively(struct node *header)
{
    if(header == NULL)
    {
        printf("\n");
        return;
    }
    else
    {
        printf("%4d", header->key);
        printListRecursively(header->next);
    }
}

void printReverseListRecursively(struct node *header)
{
    if(header==NULL)
    {
        printf("\n");
        return;
    }
    printReverseListRecursively(header->next);
    printf("%4d", header->key);
}

void destroyList(struct node **header)
{
    struct node *temp=*header;
    while(*header!=NULL)
    {
        *header=(*header)->next;
        free(temp);
        temp=*header;
    }
    free(*header);
}

void deleteLastFirstNode(struct node **header)
{
    if(*header==NULL)
    {
        exit(1);
    }
    struct node *first=*header;
    struct node *last=*header;

    while(last->next->next!=NULL)
    {
        last = last->next;
    }
    free(last->next);
    last->next=NULL;

    *header=(*header)->next;
    free(first);
}

void reverseList(struct node **list)
{

    struct node *a= *list;
    struct node *b = (*list)->next;

    while(b->next!=NULL)
    {
        b->next=a;
        b=a->next->next;
        a=a->next;

    }
    *list=b;
}

void end_to_start(struct node** list)
{
    if(*list == NULL) return;
    if((*list)->next == NULL) return;
    struct node *start = (*list), *previous = NULL, *end=(*list);
    while(end->next != NULL)
    {
        previous = end;
        end = end->next;
    }
    previous->next = start;
    *list = end;
    (*list)->next=start->next;
    start->next=NULL;
}


int main()
{
    struct node *header=NULL;
    addListEnd(&header, 10);
    addListEnd(&header, 15);
    addListEnd(&header, 20);
    addListEnd(&header, 25);
    addListEnd(&header, 98);
    addListEnd(&header, 80);
    printList(header);
    end_to_start(&header);
    printList(header);


    return 0;

}
