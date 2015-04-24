// http://geeksquiz.com/binary-search-tree-set-2-delete/

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

Node getSuccessor(Node root)
{
    Node current = root;
    while(current->left !=NULL)
        current = current->left;
    return current;
}

Node deleteNode(Node root, int key)
{
    // Base case 1 : Not found in this subtree
    if(root == NULL) return root;
    Node temp ;

    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }

    else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }

    else {
        // Base case 2 : node with only one child or no child
        if(root->right == NULL){
            temp = root->left;
            delete(root);
            return temp;
        }
        // Base case 2 :
        if(root->left == NULL){
            temp = root->right;
            delete(root);
            return temp;
        }
        // Base case 3 : Both subtree non-empty
        Node succ = getSuccessor(root->right);
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
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

    int del =10;
    root = deleteNode(root, del);
    cout<<"\n\ndeleting..."<<del<<endl;
    cout<<"Size of tree is "<<sizeOfTree(root)<<endl;
    inOrder(root);

    del =5;
    root = deleteNode(root, del);
    cout<<"\n\ndeleting..."<<del<<endl;
    cout<<"Size of tree is "<<sizeOfTree(root)<<endl;
    inOrder(root);

    del =10;
    root = deleteNode(root, del);
    cout<<"\n\ndeleting..."<<del<<endl;
    cout<<"Size of tree is "<<sizeOfTree(root)<<endl;
    inOrder(root);

    del =15;
    root = deleteNode(root, del);
    cout<<"\n\ndeleting..."<<del<<endl;
    cout<<"Size of tree is "<<sizeOfTree(root)<<endl;
    inOrder(root);

    del =20;
    root = deleteNode(root, del);
    cout<<"\n\ndeleting..."<<del<<endl;
    cout<<"Size of tree is "<<sizeOfTree(root)<<endl;
    inOrder(root);

    del =0;
    root = deleteNode(root, del);
    cout<<"\n\ndeleting..."<<del<<endl;
    cout<<"Size of tree is "<<sizeOfTree(root)<<endl;
    inOrder(root);

    return 0;
}
