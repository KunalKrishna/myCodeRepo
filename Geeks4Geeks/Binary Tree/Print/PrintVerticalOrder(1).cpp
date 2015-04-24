// http://www.geeksforgeeks.org/print-binary-tree-vertical-order/
// Print a Binary Tree in Vertical Order | Set 1

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

void findMinMax(Node root, int *min, int *max, int hd)
{
    if(root == NULL) return;
    if(hd < *min)
        *min = hd;
    if(hd > *max)
        *max = hd;

    findMinMax(root->left , min, max, hd-1);
    findMinMax(root->right, min, max, hd+1);

}

void printVerticalLine(Node root, int lineNum, int hd)
{
    if(root == NULL) return;
    if(lineNum == hd)
        cout<<root->data<<" ";

    printVerticalLine(root->left , lineNum, hd-1);
    printVerticalLine(root->right, lineNum, hd+1);
}

void verticalOrder(node* root)
{
    int min =0, max =0;
    findMinMax(root, &min, &max, 0);

    for(int line=min; line<=max; line++){
        printVerticalLine(root, line, 0);
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
    verticalOrder(root);

    return 0;
}
