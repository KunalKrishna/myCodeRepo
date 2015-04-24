// find no of paths having sum K

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
    //struct node* newNode = (struct node*)malloc(sizeof(struct node));
    Node newNode = new node;
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrder(struct node* root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
        cout<<root->data<<" ";
    inOrder(root->right);
}

int pathsHvingSumK(Node root, int sum)
{
    if(root == NULL)
        return (sum == 0)? 1:0;

    int remainder = sum - (root->data);

    if( remainder == 0 && root->left == NULL && root->right == NULL){
        return 1;
    }

    return pathsHvingSumK(root->left, remainder) + pathsHvingSumK( root->right, remainder);
}

int main()
{
    struct node* root = newNode(2);
    root->left = newNode(4);
    root->left->left = newNode(1);

    root->left->right = newNode(1);

    root->right = newNode(1);
    root->right->left = newNode(4);

    root->right->right = newNode(2);
    root->right->right->right = newNode(2);

    inOrder(root);
    int K = 7;
    cout<<"No of paths having sum "<<K<<"= "<<pathsHvingSumK(root,K)<<endl;
    return 0;
}
