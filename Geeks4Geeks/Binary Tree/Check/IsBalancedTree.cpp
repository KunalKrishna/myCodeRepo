//  http://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/

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

bool isBalancedUtil(Node root, int *height)
{
    int lh=0;
    int rh=0;
    int l=0,r=0;
    if(root==NULL)
    {
        *height=0;
        return 1;
    }
    l = isBalancedUtil(root->left, &lh);
    r = isBalancedUtil(root->right, &rh);

    *height =(lh>rh? lh : rh) +1;

    if(lh-rh >= 2 || rh-lh>= 2)
        return 0;

    return l&&r;
}

bool isBalanced(Node root)
{
    int h = 0;
    return isBalancedUtil(root, &h);
}


int main()
{
    /* Constructed binary tree is
                 1
               /   \
             2      3
           /  \    /
         4     5  6
        /
       7
    */
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->left->left->left = newNode(7);
    //root->left->left->left->left = newNode(8);

    if(isBalanced(root))
        cout<<"Tree is balanced";
    else
        cout<<"Tree is NOT balanced";

    return 0;
}
