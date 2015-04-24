// http://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/

#include<iostream>
#include<climits>
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

int max(int a, int b)
{
    return (a >= b)? a: b;
}

int maxPathSumUtil(Node root, int &res)
{
    if (root==NULL) return 0;

    int lLPSum = maxPathSumUtil(root->left, res);
    int rLPSum = maxPathSumUtil(root->right, res);

    int curr_sum = max((lLPSum+rLPSum+root->data), max(lLPSum, rLPSum));

    if (res < curr_sum)
        res = curr_sum;

    return max(lLPSum, rLPSum)+root->data;
}

int maxPathSum(Node root)
{
    int res = 0;
    maxPathSumUtil(root, res);
    return res;
}

int main()
{
    Node root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);
    cout << "Max pathSum of the given binary tree is " << maxPathSum(root);
    return 0;
}
