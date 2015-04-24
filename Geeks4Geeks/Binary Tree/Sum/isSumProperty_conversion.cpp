// http://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property/

#include<iostream>
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
    struct node* newNode = new node;
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrder(struct node* root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
    cout<<root->data << " ";
    inOrder(root->right);
}

void increment(Node root, int diff)
{
    if(root->left) {
        root->left->data += diff;
        increment(root->left, diff);
    }
    else if(root->right) {
        root->right->data += diff;\
        increment(root->right, diff);
    }
}

void convertTree(Node root)
{
    int lData = 0;
    int rData = 0;

    if(root == NULL ||
                      root->left==NULL && root->right==NULL)
        return ;
    else {
        convertTree(root->left);
        convertTree(root->right);

        if(root->left != NULL)
            lData = root->left->data;

        if(root->right != NULL)
            rData = root->right->data;

        int diff = lData+rData - root->data;
        if(diff > 0)
            root->data = root->data + diff;

        if(diff < 0)
            increment(root, -diff);
    }
}

int main()
{
    struct node *root = newNode(50);
    root->left        = newNode(7);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->right = newNode(5);
    root->right->left  = newNode(1);
    root->right->right = newNode(30);

    cout<<"Inorder traversal before conversion ";
    inOrder(root);

    convertTree(root);

    cout<<"\nInorder traversal after conversion ";
    inOrder(root);

    return 0;
}
