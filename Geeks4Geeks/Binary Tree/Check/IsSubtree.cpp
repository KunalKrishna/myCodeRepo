// http://www.geeksforgeeks.org/check-if-a-binary-tree-is-subtree-of-another-binary-tree/

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
        cout<<root->data<<" ";
    inOrder(root->right);
}

bool areIdentical(Node T, Node S)
{
    if(!T && !S)
        return true;
    if(!T || !S)
        return false;
    return (T->data == S->data &&
            areIdentical(T->left, S->left) &&
            areIdentical(T->right, S->right));
}

bool isSubtree(Node T, Node S)
{
    if(S == NULL)
        return true;
    if(T == NULL)
        return false;
    if(areIdentical(T,S))
        return true;
    return ( isSubtree(T->left,S) ||
             isSubtree(T->right, S));
}

int main()
{
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    struct node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);

    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    struct node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);


    if (isSubtree(T, S))
        cout<<"Tree S IS subtree of tree T";
    else
        cout<<"Tree S is NOT a subtree of tree T";

    return 0;
}
