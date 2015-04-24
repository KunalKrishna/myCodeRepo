//  http://www.geeksforgeeks.org/find-closest-leaf-binary-tree/

#include<iostream>
#include<climits>
using namespace std;

struct node
{
    char data;
    node* left;
    node* right;
};
typedef struct node* Node;
typedef struct node** NodeRef;

struct node* newNode(char newData)
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
int getMin(int a, int b)
{
    return (a<b)?a:b;
}

int closestDown(Node root)
{
    if(root ==NULL)
        return INT_MAX;
    if(isLeaf(root))
        return 0;
    return 1 + getMin(closestDown(root->left), closestDown(root->right));
}

int findClosestUtil(Node root, Node *ancestors, char key, int idx)
{
    if(root == NULL)
        return INT_MAX;
    if(root->data == key)
    {
        int res = closestDown(root);

        for(int i=idx-1; i>=0; i--)
            res = getMin(res, idx - i + closestDown(ancestors[i]));
        return res;
    }
    ancestors[idx] = root;
    return getMin(findClosestUtil(root->left, ancestors, key, idx+1) ,
                  findClosestUtil(root->right, ancestors, key, idx+1));
}

int findClosest(Node root, char key)
{
    Node ancestors[100];
    return findClosestUtil(root, ancestors, key, 0);
}

int main()
{
    Node root                = newNode('A');
    root->left               = newNode('B');
    root->right              = newNode('C');
    root->right->left        = newNode('E');
    root->right->right       = newNode('F');
    root->right->left->left  = newNode('G');
    root->right->left->left->left  = newNode('I');
    root->right->left->left->right = newNode('J');
    root->right->right->right      = newNode('H');
    root->right->right->right->left = newNode('K');

    char k = 'H';
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
    k = 'C';
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
    k = 'E';
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
    k = 'B';
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;

    return 0;
}
