// http://www.geeksforgeeks.org/find-the-minimum-element-in-a-binary-search-tree/

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

Node minimumValueNode(Node root)
{
    if(root == NULL) return root;
    Node current = root;

    while(current->left != NULL)
         current = current->left
         ;

    return current;
}

int main()
{
    struct node* root = NULL;
    insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 0);
    insertNode(root, 20);
    insertNode(root, 1);
    cout<<"Size of tree is "<<sizeOfTree(root)<<endl;
    inOrder(root);

    cout<<endl<<endl;
    int key = 80;
    Node min;
    if( (min = minimumValueNode(root)) ){
        cout<<"Minimum Value = "<<min->data;
    }else{
        cout<<"Empty tree";
    }

    return 0;
}
