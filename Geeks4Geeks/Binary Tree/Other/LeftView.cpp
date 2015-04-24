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

void leftViewUtil(Node root, int lvl, map<int, int> &m)
{
    if(!root) return;
    if(!m.count(lvl)>0){
        m.insert(pair<int,int>(lvl, root->data));
        cout<<root->data<<" ";
    }
    // inorder
    leftViewUtil(root->left, lvl+1, m);
    leftViewUtil(root->right, lvl+1, m);
}

/*
using map, a bit_map array could have also been used
or why not use a max_level variable ??
*/
void leftView(Node root)
{
    map<int, int> m;
    leftViewUtil(root,0, m);
}

int main()
{
//    struct node *root = newNode(1);
//    root->left = newNode(2);
//    root->right = newNode(3);
//    root->left->left = newNode(4);
//    root->left->right = newNode(5);
//    root->left->right->right = newNode(11);
//    root->left->right->right->right = newNode(87);
//    root->right->left = newNode(6);
//    root->right->right = newNode(7);
//    root->right->left->right = newNode(8);

    struct node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
    root->right->right->left = newNode(68);
    leftView(root);

    return 0;
}
