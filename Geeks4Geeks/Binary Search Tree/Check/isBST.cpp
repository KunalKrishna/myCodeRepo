// http://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

#include<iostream>
#include <climits>
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

void insertNode(Node &root, int key)
{
    if(root == NULL)
        root = newNode(key);
    else{
        if(root->data > key)
            insertNode(root->left, key);
        else
            insertNode(root->right, key);
    }
}

bool isBSTUtil(Node root, int min, int max)
{
    if(root == NULL) return true;

     if (root->data < min || root->data > max)
        return 0;

    return isBSTUtil(root->left,  min, root->data-1) &&
            isBSTUtil(root->right, root->data+1, max);

}

bool isBST(Node root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

bool isBSTUtil2(Node root, Node &prev)
{
    if(root){
        if(!isBSTUtil2(root->left, prev))
            return false;

        if(prev!=NULL &&  prev->data > root->data)
            return false;

        prev = root;

        return isBSTUtil2(root->right, prev);
    }
    return true;
}

bool isBST2(Node root)
{
    Node prev = NULL;
    return isBSTUtil2(root, prev);
}

int main()
{
    struct node *root = newNode(0);
    root->left        = newNode(-1);

    if( isBST2(root))
        cout<<"Is BST\n";
    else
        cout<<"Not a BST\n";

    return 0;
}
