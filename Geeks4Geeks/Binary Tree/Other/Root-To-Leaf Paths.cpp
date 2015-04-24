// http://www.geeksforgeeks.org/given-a-binary-tree-print-out-all-of-its-root-to-leaf-paths-one-per-line/

#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

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

void printArray(int paths[], int length)
{
    for(int i = 0; i< length; i++){
        cout<<paths[i]<<" ";
    }
    cout<<"\n";
}


void _rootToLeafPathsRec(struct node* root, int paths[], int pathlength)
{
    if(root == NULL) return;
    paths[pathlength++] = root->data;

    // if leaf node
    if(root->left == NULL && root->right == NULL)
        printArray(paths,pathlength);
    else{
        _rootToLeafPathsRec(root->left,paths,pathlength);
        _rootToLeafPathsRec(root->right,paths,pathlength);
    }
}

void rootToLeafPaths(struct node* root)
{
    int paths[1000];
    _rootToLeafPathsRec(root, paths, 0);
}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    struct node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->left->left = newNode(3);
    root2->left->left->left = newNode(4);

    root2->right = newNode(5);
    root2->right->right = newNode(6);
    root2->right->right->right = newNode(7
                                         );

    cout<<"root2 : inOrder\n";
    inOrder(root2);

    cout<<"\nAll root to leaf paths... \n";
    rootToLeafPaths(root2);
    return 0;
}
