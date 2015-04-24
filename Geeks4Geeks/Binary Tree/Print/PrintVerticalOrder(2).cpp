// http://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/
// Print a Binary Tree in Vertical Order | Set 2

#include<iostream>
#include<vector>
#include<map>

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

void getVerticalOrder(Node root, int hd, map<int, vector<int> > &m)
{
    if(root ==NULL) return;
    m[hd].push_back(root->data);

    getVerticalOrder(root->left , hd-1, m);
    getVerticalOrder(root->right, hd+1, m);
}

void printVerticalOrder(node* root)
{
    map<int, vector<int> > m;
    getVerticalOrder(root, 0, m);

    map<int, vector<int> > :: iterator it;
    for(it = m.begin(); it != m.end(); it++)
    {
        for(int i=0; i< it->second.size(); i++)
            cout<<it->second[i]<<" ";
        cout<<endl;
    }
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);

    return 0;
}
