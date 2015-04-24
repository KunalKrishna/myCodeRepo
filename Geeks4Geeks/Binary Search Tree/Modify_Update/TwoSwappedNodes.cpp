// http://www.geeksforgeeks.org/fix-two-swapped-nodes-of-bst/

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

Node searchNode(Node root, int key)
{
    if(root == NULL || root->data == key)
        return root;

    if(root->data < key)
        return searchNode(root->right, key);
    return searchNode(root->left, key);
}

int main()
{
    struct node* root = NULL;
    insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 0);
    insertNode(root, 20);

    cout<<"Size of tree is "<<sizeOfTree(root)<<endl;
    inOrder(root);

    cout<<endl<<endl;
    int key = 80;
    if(searchNode(root,key)){
        cout<<key<<" found in given tree.";
    }else{
        cout<<key<<" doesn't exist in given tree";
    }

    return 0;
}
