// http://www.geeksforgeeks.org/write-a-c-program-to-calculate-size-of-a-tree/

#include<iostream>
using namespace std;

struct node{

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
    if(root){
        inOrder(root->left);
            cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int sizeOfTree(struct node* root)
{
    if(root == NULL){
        return 0;
    }
    return sizeOfTree(root->left)+1+sizeOfTree(root->right);
}

int main(){

    struct node* root = newNode(1);
    cout<<"Size of tree is "<< sizeOfTree(root)<<endl;
    root->left = newNode(2);
    cout<<"Size of tree is "<< sizeOfTree(root)<<endl;
    root->right = newNode(3);
    cout<<"Size of tree is "<< sizeOfTree(root)<<endl;
    root->left->left = newNode(4);
    cout<<"Size of tree is "<< sizeOfTree(root)<<endl;
    root->left->right = newNode(5);
    cout<<"Size of tree is "<< sizeOfTree(root)<<endl;
    root = NULL;
    cout<<"Size of tree is "<< sizeOfTree(root)<<endl;
    return 0;
}
