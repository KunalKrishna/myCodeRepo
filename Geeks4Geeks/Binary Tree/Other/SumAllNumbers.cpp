// http://www.geeksforgeeks.org/sum-numbers-formed-root-leaf-paths/

#include<iostream>
#include<vector>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};
typedef struct node* Node;
typedef struct node** NodeRef;

Node newNode(int newData)
{
    //struct node* newNode = (struct node*)malloc(sizeof(struct node));
    Node newNode = new node;
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrder(Node root)
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

int sum(vector<int> v)
{
    int s=0;
    for(int i=0; i<v.size(); i++){
        s = s*10 + v[i];
    }
    return s;
}

int treePathsSumUtil(Node root, int val)
{
    if(!root )
        return 0;
    val= val*10 + root->data;
    if( isLeaf(root) ){
        return val;
    }

    int l = treePathsSumUtil(root->left, val);
    int r = treePathsSumUtil(root->right, val);
    return l+r;
}

int treePathsSum(Node root)
{
    if(!root) return 0 ;

    return treePathsSumUtil(root, 0);
}

int main()
{
    Node root         = newNode(6);
    root->left        = newNode(3);
    root->right       = newNode(5);
    root->right->right= newNode(7);
    root->left->left  = newNode(2);
    root->left->right = newNode(5);
    root->right->right = newNode(4);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);
    cout<<"Sum of all paths is "<< treePathsSum(root);
    return 0;
}
