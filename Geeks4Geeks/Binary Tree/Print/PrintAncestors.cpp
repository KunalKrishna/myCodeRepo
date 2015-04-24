// http://www.geeksforgeeks.org/print-ancestors-of-a-given-node-in-binary-tree/

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


bool printAncestors(node* root, int target)
{
    if(root == NULL )
        return false;

    if(root->data == target)
        return true;

    if(printAncestors(root->left, target) || printAncestors(root->right, target))
    {
        cout<<root->data<<" ";
        return true;
    }
    return false;
}

int main()
{
    /* Constructed binary tree is
                1
              /   \
            2      3
          /  \    /
        4     5  8
    */
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(8);

    int target = 8;
    for(int i=1; i<10; i++){
        cout<<"Ancestors of "<<i<<" : ";
        if(!printAncestors(root, i)){
            cout<<"Given target doesnt exist in tree";
        }
        cout<<endl;
    }

    return 0;
}
