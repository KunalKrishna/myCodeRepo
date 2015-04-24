// http://www.geeksforgeeks.org/remove-bst-keys-outside-the-given-range/

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

Node removeOutsideRange(Node root, int min, int max)
{
    if(root){
        root->left = removeOutsideRange(root->left, min, max);
        root->right = removeOutsideRange(root->right, min, max);

        if(root->data < min){
            Node rChild = root->right;
            delete root;
            return rChild;
        }
        if(root->data > max){
            Node lChild = root->left;
            delete(root);
            return lChild;
        }
        return root;
    }
    return NULL;
}

int main()
{
    node* root = NULL;
    insertNode(root, 6);
    insertNode(root, -13);
    insertNode(root, 14);
    insertNode(root, -8);
    insertNode(root, 15);
    insertNode(root, 13);
    insertNode(root, 7);

    cout << "Inorder traversal of the given tree is: ";
    inOrder(root);

    root = removeOutsideRange(root, -10, 13);

    cout << "\nInorder traversal of the modified tree is: ";
    inOrder(root);

    return 0;
}
