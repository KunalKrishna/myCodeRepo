// http://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/
// Print all nodes at distance k from a given node
#include<iostream>
#include<vector>

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

void printkdistanceDownNode(node* root, int k)
{
    if( !root || k<0)
        return ;

    if(k==0)
        cout<<root->data<<endl;

    printkdistanceDownNode(root->left , k-1);
    printkdistanceDownNode(root->right, k-1);
}

int printkdistanceNode(node* root, node* target, int k)
{
    if( !root) return -1 ;//NOT FOUND IN THIS SUBTREE

    if(root == target)
    {
        printkdistanceDownNode(root,k);
        return 0;
    }

    int dl = printkdistanceNode(root->left, target, k);
    // IF FOUND IN LEFT SUBTREE
    if( dl != -1){

        if(dl+1 == k){
            cout<<"*"<<root->data<<endl;
        }
        else
            printkdistanceDownNode(root->right, k-dl-2);

        return dl+1;
    }

    int dr = printkdistanceNode(root->right, target, k);
    if( dr != -1){

        if( dr+1 == k){
            cout<<"*"<<root->data<<endl;
        }
        else
            printkdistanceDownNode(root->left, k-dr-2);

        return dr+1;
    }

    return -1;
}

int main(){
    node * root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    node * target = root->left->right;
    printkdistanceNode(root, target, 2);
    return 0;
}
