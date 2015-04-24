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

bool printPath(Node root, Node target_leaf)
{
    if(root== NULL)
        return false;
    if(root == target_leaf || printPath(root->left, target_leaf) || printPath(root->right, target_leaf) )
    {
        cout<<root->data<<" ";
        return true;
    }
    return false;
}

void getTargetLeaf(Node root, int *max_sum_ref, int curr_sum, node **target_leaf_ref)
{
    if(root==NULL)
        return;

    curr_sum += root->data;

    if(root->left == NULL && root->right==NULL)
        if(curr_sum > *max_sum_ref)
        {
            *max_sum_ref = curr_sum;
            *target_leaf_ref = root;
        }
    getTargetLeaf(root->left, max_sum_ref, curr_sum, target_leaf_ref);
    getTargetLeaf(root->right, max_sum_ref, curr_sum, target_leaf_ref);
}

int maxSumPath(Node root)
{
    if(root==NULL)
        return 0;

    int max_sum = INT_MIN;
    Node target_leaf ;

    getTargetLeaf(root, &max_sum, 0, &target_leaf);

    printPath(root, target_leaf);

    return max_sum;
}

int main()
{
    struct node *root = NULL;

    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(1);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);

    cout<<"Following are the nodes on the maximum sum path \n";
    int sum = maxSumPath(root);
    cout<<"\nSum of the nodes is "<<sum;

    return 0;
}
