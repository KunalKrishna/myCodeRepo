// http://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/

#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};
typedef struct node* Node;
typedef struct node** NodeRef;

struct node* newNode(int newData)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrder(struct node* root){

    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

struct node* lca(node* root, int n1, int n2)
{
    if(root == NULL)
        return NULL;
    int current_root_data = root->data;
    if(current_root_data < n1 && current_root_data < n2)
        return lca(root->right, n1, n2);
    if(current_root_data > n1 && current_root_data > n2)
        return lca(root->left, n1, n2);
    return root;
}

int main()
{
    struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    inOrder(root);
    int n1 = 10, n2 = 14;
    struct node *t = lca(root, n1, n2);
    printf("\n\nLCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    return 0;
}
