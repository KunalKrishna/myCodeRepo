// http://www.geeksforgeeks.org/check-two-nodes-cousins-binary-tree/

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* left, *right;
};

struct node *newNode(int item)
{
    struct node *temp =  new node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

bool isSibling(node *root, node *a, node *b)
{
    if(root==NULL) return false;
    return (root->left==a && root->right==b ||
            root->right==b && root->left==a ||
            isSibling(root->left,a,b) ||
            isSibling(root->right,a,b)
            );
}

int level(node *root, node *a, int i)
{
    if(root==NULL) return 0;
    if(root==a) return i;

    int l = level(root->left, a, i+1);
    if(l!=0) return l;
    int r = level(root->right, a, i+1);
    return r;
}

bool isCousin(node *root, node *Node1, node *Node2)
{
    if(level(root,Node1,1) == level(root,Node2,1)
       && !isSibling(root,Node1,Node2))
        return true;
    return false;
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(15);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    struct node *Node1,*Node2;
    Node1 = root->left->left;
    Node2 = root->right->right;

    if(isCousin(root,Node1,Node2))
        cout<<"Yes";
    else
        cout<<"No";

    return 0;
}
