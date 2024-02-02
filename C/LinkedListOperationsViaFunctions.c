#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* create_newnode(int a)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=a;
    newnode->next=NULL;
    return newnode;
}

void add_newnode_to_head(struct node **head, int a)
{
    struct node *newnode=create_newnode(a);
    newnode->next=*head;
    *head=newnode;
}

void add_newnode_to_end(struct node **head, int a)
{
    struct node *newnode=create_newnode(a), *temp;
    newnode->next=NULL;
    temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}

void add_newnode_specific(struct node **head, int a, int position)
{
    struct node *newnode=create_newnode(a);
    struct node *temp=*head;
    int i=1;
    if(*head=NULL)
    {
        *head=newnode;
    }
    else
    {
        while(i<position-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}


void print_list(struct node *head)
{
    while(head!=NULL)
    {
        printf(" %d \n", head->data);
        head=head->next;
    }
    printf("\n");
}
void print_list_recursive(struct node *head)
{
    if(head!=NULL)
    {
        printf("%d\n", head->data);
        print_list_recursive(head->next);
    }
}

void delete_node(struct node* *head)
{
    struct node* head2;
    head2=*head;
    (*head)=(*head)->next;
    free(head2);
}

void print_reverse_recursive(struct node *head)
{
    if(head!=NULL)
    {
        print_reverse_recursive(head->next);
        printf(" %4d ", head->data);
    }
}

void reverse_recursive(struct node **head)
{
    if(*head!=NULL)
    {
        reverse_recursive(&((*head)->next));
        *head=(*head)->next;
    }

}


void add_sorted_list(int data, struct node **head)
{
    struct node *a, *b, *newnode;
    b=*head;
    while(b!=NULL && b->data <= data)
    {
        if(b->data==data) return;
        a = b;
        b= b->next;
    }
    newnode=create_newnode(data);
    if(b==*head)
    {
        newnode->next=*head;
        *head=newnode;
    }
    else
    {
        a->next=newnode;
        newnode->next=b;

    }
}

void delete_specific(int loc, struct node **head)
{
    int i=1;
    struct node *temp;
    struct node *inter;
    temp=inter=*head;
    while(i<loc-1)
    {
        if(temp==NULL)
        {
            printf("You cant delete something that doesnt exist.");;
            temp=temp->next;
        }
        inter=temp->next;
        temp->next=inter->next;
        free(inter);
    }
}


int main()
{
    struct node *head=NULL;
    add_newnode_to_head(&head,5);
    print_list(head);
    add_newnode_to_end(&head,3);
    print_list(head);
}

