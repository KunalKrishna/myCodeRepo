//  http://www.geeksforgeeks.org/check-leaves-level/

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

bool isLeaf(Node root)
{
    if(!root) return false;
    if(!root->left && !root->right)
        return true;
    return false;
}

bool checkUtil(Node root, int lvl, int &leafLevel)
{
    if(!root) return true;
    if(isLeaf(root) ){
        if(leafLevel == 0){
            //sets depth of first leaf ever found
            leafLevel = lvl;
            return true;
        } else if(lvl == leafLevel){
            // compares the depths of subsequent leaves found in tree with that of first leaf ever found
            return true;
        }
        return false;
    }
    return checkUtil(root->left, lvl+1, leafLevel) &&
            checkUtil(root->right, lvl+1, leafLevel);
}

bool check(Node root)
{
    int leafLevel=0;
    return checkUtil(root, 0, leafLevel);
}

int main()
{
    struct node *root = newNode(12);
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
    if (check(root))
        cout<<"Leaves are at same level\n";
    else
        cout<<"Leaves are not at same level\n";
    return 0;
}
