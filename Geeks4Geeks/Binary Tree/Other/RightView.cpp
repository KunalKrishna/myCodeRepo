//http://www.geeksforgeeks.org/print-right-view-binary-tree-2/

#include<iostream>
#include<map>
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
    if(root == NULL)
        return;
    inOrder(root->left);
        cout<<root->data<<" ";
    inOrder(root->right);
}

void rightViewUtil(Node root, int lvl, map<int, int> &m)
{
    if(!root) return;
    if(!m.count(lvl)>0){
        m.insert(pair<int,int>(lvl, root->data));
        cout<<root->data<<" ";
    }
    //reverse inorder
    rightViewUtil(root->right, lvl+1, m);
    rightViewUtil(root->left, lvl+1, m);
}

/*
using map, a bit_map array could have also been used
or why not use a max_level variable ??
*/
void rightView(Node root){
    map<int, int> map;
    rightViewUtil(root,0, map);
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(11);
    root->left->right->right->right = newNode(87);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    rightView(root);

    return 0;
}
