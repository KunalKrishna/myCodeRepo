// http://www.geeksforgeeks.org/find-distance-two-given-nodes/

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
        cout<<root->data;
    inOrder(root->right);
}

int findLevel(Node root, int key, int lvl)
{
    if(!root) return -1;

    if(root->data == key)
        return lvl;
    int l = findLevel(root->left, key, lvl+1);

    return (l != -1)? l : findLevel(root->right, key, lvl+1);
}

Node findDistanceUtil(Node root, int &d1, int &d2, int n1, int n2, int &dist, int lvl)
{
    if(root==NULL) return root;

    if(root->data == n1)
    {
        d1 = lvl;
        return root;
    }
    if(root->data == n2)
    {
        d2 = lvl;
        return root;
    }
    Node lLca = findDistanceUtil(root->left,  d1, d2, n1, n2, dist, lvl+1);
    Node rLca = findDistanceUtil(root->right, d1, d2, n1, n2, dist, lvl+1);

    if(lLca && rLca){
        dist = d1 + d2 - 2*lvl;
        return root;
    }
    return (lLca != NULL)? lLca : rLca;
}

int findDistance(Node root, int n1, int n2)
{
    int d1 = -1;
    int d2 = -1;
    int dist;

    Node lca = findDistanceUtil(root, d1, d2, n1, n2, dist, 1);
    if( d1 != -1 && d2 != -1)
        return dist;

    if( d1 != -1)
        return findLevel(lca, n2, 0);

    if( d2 != -1)
        return findLevel(lca, n1, 0);

    return -1;
}

int main()
{

    Node root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = "   << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
    return 0;
}
