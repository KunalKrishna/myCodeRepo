//  http://www.geeksforgeeks.org/find-depth-of-the-deepest-odd-level-node/

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

void deepestOddLeafUtil(Node root, int lvl, int &maxLvl)
{
    if(!root) return ;
    if(lvl%2==1 && isLeaf(root) && lvl > maxLvl)
    {
        maxLvl = lvl;
        return;
    }
    deepestOddLeafUtil(root->left,  lvl+1, maxLvl);
    deepestOddLeafUtil(root->right, lvl+1, maxLvl);
}

int deepestOddLeaf(Node root)
{
    int maxDepth = -1;
    deepestOddLeafUtil(root, 1, maxDepth);
    return maxDepth;
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

    int depth = deepestOddLeaf(root);
    if (depth == -1)
        cout << "None" << endl;
    else
        cout << depth<<endl;

    return 0;
}
