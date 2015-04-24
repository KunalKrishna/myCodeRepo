// http://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/

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


bool hasPathSum(node* root, int sum)
{
    if(root == NULL)
        return (sum==0);

    int subSum = sum - (root->data);
    if(subSum ==0 && root->left==NULL && root->right ==NULL)
        return true;

    bool ans = false;
    if(root->left)
      ans = hasPathSum(root->left, subSum);
    if(root->right)
      ans = ans || hasPathSum(root->right, subSum);

    return ans;
}

bool hasPathSum2(node* root, int sum)
{
    if(root == NULL)
        return (sum==0);

    int subSum = sum - (root->data);
    if( subSum ==0 && root->left==NULL && root->right ==NULL
        || (root->left  && hasPathSum(root->left,  subSum) )
        || (root->right && hasPathSum(root->right, subSum) )
      )
        return true;

    return false;
}

int main(){

    /* Constructed binary tree is
             10
           /   \
         8      2
        /  \    /
      3     5  2
   */
    struct node *root = newNode(10);
    root->left        = newNode(8);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);

    int sum = 0;
    if(hasPathSum(NULL, sum))
        cout<<"\nThere is a root-to-leaf path with sum "<< sum;
    else
        cout<<"\nThere is no root-to-leaf path with sum "<< sum;

    if(hasPathSum2(NULL, sum))
        cout<<"\nThere is A Root-to-leaf path with sum "<< sum;
    else
        cout<<"\nThere is NO Root-to-leaf path with sum "<< sum;


    int testCaes[] = {18, 12, 0, 10, 21, 23, 14};

    for(int i=0; i<7; i++)
    {
        sum = testCaes[i];
        cout<<endl;
        if(hasPathSum(root, sum))
            cout<<"\nThere is a root-to-leaf path with sum "<< sum;
        else
            cout<<"\nThere is no root-to-leaf path with sum "<< sum;

        if(hasPathSum2(root, sum))
            cout<<"\nThere is A Root-to-leaf path with sum "<< sum;
        else
            cout<<"\nThere is NO Root-to-leaf path with sum "<< sum;
    }
    cout<<endl;
    return 0;
}
