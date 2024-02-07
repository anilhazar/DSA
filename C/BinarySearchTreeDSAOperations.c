#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node* left;
    struct node* right;
};

struct tree
{
    struct node* root;
};

struct tree* createTree()
{
    struct tree* temp = (struct tree*)malloc(sizeof(struct tree));
    if (temp == NULL)
    {
        printf( "Memory allocation failed.\n");
        exit(1);
    }
    temp->root = NULL;
    return temp;
}


struct node* createNode(int key)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    temp->left = NULL;
    temp->right = NULL;
    temp->key = key;
    return temp;
}

void insertNode(struct tree* tree, int key)
{
    struct node* toBeAdded = createNode(key);
    struct node* root = tree->root;

    if (root == NULL)
    {
        tree->root = toBeAdded;
        return;
    }

    struct node* current = tree->root;
    struct node* parent = NULL;

    while (current != NULL)
    {
        parent = current;

        if (key > current->key)
        {
            current = current->right;
        }
        else if (key < current->key)
        {
            current = current->left;
        }
        else
            break;

    }

    if (key > parent->key)
    {
        parent->right = toBeAdded;
    }
    else
    {
        parent->left = toBeAdded;
    }

}

void findParentGrandParent(struct tree *tree, int key)
{
    struct node *current = tree->root;
    struct node *parent = NULL;
    struct node *grandParent = NULL;

    while(current->key != key)
    {
        grandParent = parent;
        parent = current;
        if(key > current->key)
        {
            current = current->right;
        }
        else if (key < current->key)
        {
            current = current->left;
        }
        else
            break;

    }
    printf("Value: %d, Parent: %d, Grandparent: %d \n", current->key,
           (parent != NULL) ? parent->key : -1,
           (grandParent != NULL) ? grandParent->key : -1);

}

int are_siblings(struct node* root, struct node* A, struct node* B)
{
    if(root == NULL || root->right == NULL || root->left == NULL) return 0;
    struct node *pA = root, *pB = root, *a = root, *b = root;
    while(a->key != A->key)
    {
        pA = a;
        if(A->key > a->key)
            a = a->right;
        else
            a = a->left;
    }
    while(b->key != B->key)
    {
        pB = b;
        if(B->key > b->key)
            b = b->right;
        else
            b = b->left;
    }
    if(pA->key == pB->key)
        return 1;
    else
        return 0;

}

int findLevel(struct node* root, int key)
{
    if (root == NULL)
    {
        return 0;
    }

    int level = 1;
    struct node* temp = root;

    while (temp != NULL)
    {
        if (key == temp->key)
        {
            return level;
        }

        if (key < temp->key)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }

        level++;
    }

    return 0;
}

struct node* findMin(struct node* root)
{
    struct node* current = root;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node* findMax(struct node* root)
{
    struct node* current = root;

    while (current && current->right != NULL)
        current = current->right;

    return current;
}

int isBST(struct node* root)
{
    static struct node *prev = NULL;

    if (root)
    {
        if (!isBST(root->left))
            return 0;

        if (prev != NULL && root->key <= prev->key)
            return 0;

        prev = root;

        return isBST(root->right);
    }

    return 1;
}

int main(int argc, char** argv)
{
    struct tree* tree = createTree();

    insertNode(tree, 50);
    insertNode(tree, 200);
    insertNode(tree, 25);
    insertNode(tree, 75);
    insertNode(tree, 20);
    insertNode(tree, 35);
    insertNode(tree, 98);
    insertNode(tree, 99);
    insertNode(tree, 500);
    insertNode(tree, 400);
    insertNode(tree, 300);
    insertNode(tree, 210);
    insertNode(tree, 375);
    insertNode(tree, 30);
    insertNode(tree, 173);

    findParentGrandParent(tree, 20);
    int a = are_siblings(tree->root, tree->root->left->left,
                         tree->root->left->right);
    printf("Are siblings: %d \n", a);
    printf("Level of 25 is: %d\n", findLevel(tree->root, 25));
    printf("Level of 20 is: %d\n", findLevel(tree->root, 20));

    struct node* minNode = findMin(tree->root);
    printf("Minimum value in the tree: %d\n", minNode->key);

    struct node* maxNode = findMax(tree->root);
    printf("Maximum value in the tree: %d\n", maxNode->key);

    printf("Is the tree a binary search tree? %s\n",
           isBST(tree->root) ? "Yes" : "No");

    return 0;
}
