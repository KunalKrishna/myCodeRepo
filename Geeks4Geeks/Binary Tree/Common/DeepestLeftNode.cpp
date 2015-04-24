//  http://www.geeksforgeeks.org/deepest-left-leaf-node-in-a-binary-tree/

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
    if(root == NULL)
        return;
    inOrder(root->left);
        cout<<root->data<<" ";
    inOrder(root->right);
}

bool isLeaf(Node root)
{
    if(!root) return false;
    if(!root->left && !root->right)
        return true;
    return false;
}

void deepestLeftLeafUtil(Node root, int lvl, int &maxLvl, bool isLeft, Node &result)
{
    if(!root) return ;
    if(isLeft && isLeaf(root) && lvl >= maxLvl)
    {
        maxLvl = lvl;
        result = root;
        return ;
    }
    deepestLeftLeafUtil(root->left,  lvl+1, maxLvl,  true, result);
    deepestLeftLeafUtil(root->right, lvl+1, maxLvl, false, result);
}

Node deepestLeftLeaf(Node root)
{
    Node result = NULL;
    int maxDepth =0;
    deepestLeftLeafUtil(root, 0, maxDepth, false, result);
    return result;
}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);

    Node result = deepestLeftLeaf(root);
    if (result)
        cout << "The deepest left child is " << result->data;
    else
        cout << "There is no left leaf in the given tree";

    return 0;
}
