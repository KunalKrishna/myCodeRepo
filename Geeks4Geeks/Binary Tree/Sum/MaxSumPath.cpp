// http://www.geeksforgeeks.org/find-the-maximum-sum-path-in-a-binary-tree/

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

bool printPath (struct node *root, struct node *target_leaf)
{
    if (root == NULL)
        return false;

    if (root == target_leaf || printPath(root->left, target_leaf) ||
            printPath(root->right, target_leaf) )
    {
        cout<< root->data<<" ";
        return true;
    }
    return false;
}

void getTargetLeaf (struct node *node, int *max_sum_ref, int curr_sum,
                   struct node **target_leaf_ref)
{
    if (node == NULL)
        return;

    curr_sum = curr_sum + node->data;

    if (node->left == NULL && node->right == NULL)
    {
        if (curr_sum > *max_sum_ref)
        {
            *max_sum_ref = curr_sum;
            *target_leaf_ref = node;
        }
    }

    getTargetLeaf (node->left, max_sum_ref, curr_sum, target_leaf_ref);
    getTargetLeaf (node->right, max_sum_ref, curr_sum, target_leaf_ref);
}

int maxSumPath (struct node *node)
{
    if (node == NULL)
        return 0;

    struct node *target_leaf;
    int max_sum = INT_MIN;

    getTargetLeaf (node, &max_sum, 0, &target_leaf);

    printPath (node, target_leaf);

    return max_sum;
}

int main()
{
    struct node *root = NULL;

    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);

    cout<<"Following are the nodes on the maximum sum path \n";
    int sum = maxSumPath(root);
    cout<<"\nSum of the nodes is "<< sum;

    return 0;
}
