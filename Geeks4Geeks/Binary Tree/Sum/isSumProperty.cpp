// http://www.geeksforgeeks.org/check-for-children-sum-property-in-a-binary-tree/

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

bool isSumProperty(Node root)
{
    int lData = 0;
    int rData = 0;

    if(root == NULL ||
                      root->left==NULL && root->right==NULL)
        return true;
    if(root->left != NULL){
        lData = root->left->data;
    }
    if(root->right != NULL){
        rData = root->right->data;
    }
    return (lData+rData == root->data) &&
                            isSumProperty(root->left) && isSumProperty(root->right);
}

int main()
{
    Node root1 = newNode(10);
    root1->left = newNode(9);
    root1->right = newNode(1);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

    struct node *root  = newNode(10);
    root->left         = newNode(8);
    root->right        = newNode(2);
    root->left->left   = newNode(3);
    root->left->right  = newNode(5);
    root->right->right = newNode(2);

    //if( isSumProperty(root1) ){
    if( isSumProperty(root) ){
        cout<<"\nGiven tree holds Children Sum Property \n";
    } else {
        cout<<"\nGiven tree does NOT hold Children Sum Property \n";
    }
    return 0;
}
