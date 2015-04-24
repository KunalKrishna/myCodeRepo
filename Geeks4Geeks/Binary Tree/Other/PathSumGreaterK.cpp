// http://www.geeksforgeeks.org/remove-all-nodes-which-lie-on-a-path-having-sum-less-than-k/

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

void prunetUtil(Node &root, int sum, int K)
{
    Node lNode,rNode,temp;
    int currSum ;
    if(!root || (currSum = root->data +sum) >=K )
       return ;
    lNode=root->left;
    rNode=root->right;

    prunetUtil(root->left, currSum, K);
    prunetUtil(root->right, currSum, K);

    if( isLeaf(root) && currSum < K)
    {
        temp = root;
        delete(temp);
        root=NULL;
        return;
    }
    if( isLeaf(lNode) && currSum+lNode->data < K) {
        root->left=NULL;
        delete(lNode);
        lNode=NULL;
    }
    if( isLeaf(rNode) && currSum+rNode->data < K) {
        root->right=NULL;
        delete(rNode);
        rNode=NULL;
    }
}

Node prune(Node root, int K)
{
    int sum =0;
    prunetUtil(root, sum, K);
    return root;
}
int main()
{
    int k = 1;
    Node root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(12);
    root->right->right->left = newNode(10);
    root->right->right->left->right = newNode(11);
    root->left->left->right->left = newNode(13);
    root->left->left->right->right = newNode(14);
    root->left->left->right->right->left = newNode(15);

    cout<<"Tree before truncation\n";
    inOrder(root);

    root = prune(root, k); // k is 1
    cout<<"\n\nTree after truncation(K=1)\n";
    inOrder(root);

    k=20;
    root = prune(root, 20); // k is 20
    cout<<"\n\nTree after truncation(K=20)\n";
    inOrder(root);

    k=45;
    root = prune(root, k); // k is 45
    cout<<"\n\nTree after truncation(K=45)\n";
    inOrder(root);

    k=200;
    root = prune(root, k); // k is 200
    cout<<"\n\nTree after truncation(K=200)\n";
    inOrder(root);

    return 0;
}

