// http://www.geeksforgeeks.org/print-nodes-distance-k-leaf-node/
// Print all nodes that are at distance k from a leaf node

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

struct node* newNode(int newData)
{
    struct node* newNode = new node;
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool isLeaf(Node a)
{
    return (a!=NULL && a->left==NULL && a->right==NULL);
}

void printKDistantfromLeafUtil(node *root, int *path, int *visited, int pathLen, int k);
void printKDistantfromLeaf(node* root, int k)
{
    int MAX_HEIGHT =1000;
    int path[MAX_HEIGHT];
    int visited[MAX_HEIGHT];

    printKDistantfromLeafUtil(root, path, visited, 0, k);
}

void printKDistantfromLeafUtil(node *root, int *path, int *visited, int pathLen, int k)
{
    if(!root) return;

    path[pathLen]    = root->data;
    visited[pathLen] = false;
    pathLen++;

    int KNodesAboveIndex = pathLen-k-1;
    if( isLeaf(root) && KNodesAboveIndex>=0 && !visited[KNodesAboveIndex]){
        cout<<path[KNodesAboveIndex]<<" ";
        visited[KNodesAboveIndex]=true;
    }
    printKDistantfromLeafUtil(root->left,  path, visited, pathLen, k);
    printKDistantfromLeafUtil(root->right, path, visited, pathLen, k);
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

    cout << "Nodes at distance 1 are: ";
    printKDistantfromLeaf(root, 1);

    cout << "\nNodes at distance 2 are: ";
    printKDistantfromLeaf(root, 2);

    cout << "\nNodes at distance 3 are: ";
    printKDistantfromLeaf(root, 3);

    cout << "\nNodes at distance 5 are: ";
    printKDistantfromLeaf(root, 5);

    return 0;
}

