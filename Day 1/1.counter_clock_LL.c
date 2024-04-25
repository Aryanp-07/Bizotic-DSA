#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

void addNode(int data)
{
    if (root == NULL)
    {
        root = (struct Node *)malloc(sizeof(struct Node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        // printf("root created\n");
    }
    else
    {
        struct Node *temp = root;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->right = (struct Node *)malloc(sizeof(struct Node));
        temp->right->data = data;
        temp->right->left = temp;
        temp->right->right = NULL;
        // printf("Node created\n");
    }
}

void display()
{
    struct Node *temp = root;
    while (temp->right != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->right;
    }
    printf("%d-->", temp->data);
    printf("\n");
}

void counterclock(int N)
{
    struct Node *temp = root;
    struct Node *temp1 = root;
    struct Node *temp2 = root;
    while (temp2->right != NULL)
    {
        temp2 = temp2->right;
    }
    temp2->right = temp;
    temp->left = temp2;
    for (int i = 0; i < N; i++)
    {
        temp1 = temp1->right;
    }
    temp1->left->right = NULL;
    temp1->left = NULL;
    root = temp1;
}

void main()
{
    int N;
    int n;
    int data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &data);
        addNode(data);
    }
    display();

    printf("Enter the value of N:");
    scanf("%d", &N);
    counterclock(N);
    display();
}