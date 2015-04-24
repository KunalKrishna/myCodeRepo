// http://www.geeksforgeeks.org/find-sum-left-leaves-given-binary-tree/

#include <iostream>
using namespace std;

/* A binary tree Node has key, pointer to left and right
   children */
struct Node
{
    int val;
    struct Node* left, *right;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointer. */
Node *newNode(char k)
{
    Node *node = new Node;
    node->val = k;
    node->right = node->left = NULL;
    return node;
}

// A utility function to check if a given node is leaf or not
bool isLeaf(Node *node)
{
   if (node == NULL)
       return false;
   if (node->left == NULL && node->right == NULL)
       return true;
   return false;
}

int leftLeavesSum(Node* root){
    int res =0;
    if(root) {
        if(isLeaf(root->left)){
            res += root->left->val;
        }
        else
            res += leftLeavesSum(root->left);

        res += leftLeavesSum(root->right);
    }
    return res;
}
/// ALTERNATE METHOD

int leftLeavesSumUtil(Node* root, int direction){
    if(root == NULL ) return 0;
    if(direction == -1)//this node is left of its parent
    {
        if(isLeaf(root)){
            return root->val;
        }
        else
            return leftLeavesSumUtil(root->left, -1) + leftLeavesSumUtil(root->right,+1);
    }
    if(direction == 1)//this node is right of its parent
    {
        return leftLeavesSumUtil(root->left, -1) + leftLeavesSumUtil(root->right,+1);
    }

}
int leftLeavesSum2(Node* root){

    if(root==NULL) return 0;
    return leftLeavesSumUtil(root->left, -1)+leftLeavesSumUtil(root->right, +1);
}

int main()
{
    // Let us construct the Binary Tree shown in the
    // above figure
    struct Node *root         = newNode(20);
    root->left                = newNode(9);
    root->right               = newNode(49);
    root->right->left         = newNode(23);
    root->right->right        = newNode(52);
    root->right->right->left  = newNode(50);
    root->left->left          = newNode(5);
    root->left->right         = newNode(12);
    root->left->right->right  = newNode(12);
    cout << "Sum of left leaves is "
         << leftLeavesSum(root);

    cout << "\nSum of left leaves is uisng alt method "
         << leftLeavesSum2(root);
    return 0;
}
