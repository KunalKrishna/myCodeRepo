// http://www.geeksforgeeks.org/diameter-of-a-binary-tree/

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

int max(int a , int b ){
    return (a>=b) ? a : b;
}

int height(struct node* root){
    if(root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

// O(n^2)
int diameter(Node root){
    if(root == NULL)
        return 0;

    int lHeight= height(root->left);
    int rHeight= height(root->right);

    // the maximum of three is returned
    return max( lHeight+1+rHeight, max( diameter(root->left), diameter(root->right) ) );
}

// optimized
int diameterOpt(Node root, int &height)
{
    if(root == NULL){
        height =0;
        return 0;
    }

    int lh=0, rh=0;
    int lDiameter =0, rDiameter =0;

    lDiameter = diameterOpt(root->left, lh);
    rDiameter = diameterOpt(root->right, rh);

    height = max(lh, rh)+1;

    return max(lh+rh+1, max(lDiameter, rDiameter));
}


int main(){

    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Diameter of tree is %d \n", diameter(root));
    int h=0;
    printf("Diameter of tree is %d \n", diameterOpt(root,h));
    return 0;
}
