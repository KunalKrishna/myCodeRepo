// http://www.geeksforgeeks.org/avl-tree-set-2-deletion/

#include<iostream>
#include<cstring>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

typedef node* Node;
typedef node** NodeRef;

void inOrder(struct node *root);
int max(int a, int b);
int height(node *root);
node* newNode(int key);
node* rightRotate(node *y);
node* insert(node* node, int key);
bool isBalancedUtil(Node root, int *h);
void preOrder(struct node *root);

int main()
{
    struct node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
    */

    cout<<"In order traversal of the constructed AVL tree is \n";
    inOrder(root);

    cout<<"\nPre order traversal of the constructed AVL tree is \n";
    preOrder(root);

    int h = 0;
    if(isBalancedUtil(root, &h)){
        cout<<"\nIt IS Balanced\n";
    }
    else {
        cout<<"\nIt is NOT Balanced\n";
    }
    return 0;
}


int max(int a, int b)
{
    return (a>b)?a:b;
}

int height(struct node *N)
{
    if(N)
        return N->height;
    return 0;
}

struct node* newNode(int key)
{
    node * temp = new node;
    temp->left  = NULL;
    temp->right =  NULL;
    temp->data   = key;
    temp->height =1;
    return temp;
}

struct node *rightRotate(struct node *y)
{
    Node x = y->left;
    Node T2 = x->right;

    /* rotation beging */
    x->right = y;
    y->left  = T2;

    /* maintains height */
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct node *leftRotate(struct node *x)
{
    Node y = x->right;
    Node T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return y;
}

int getBalance(node *N)
{
    if(N)
        return height(N->left) - height(N->right);
    return 0;
}

struct node* insert(struct node* root, int key)
{
    if(!root) return newNode(key);

    if(key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    root->height  = max(height(root->left), height(root->right)) +1 ;

    int balance = getBalance(root);

    // LEFT -
    if(balance > 1) {
        //  - LEFT ROTATION
        if(key < root->left->data){
            return rightRotate(root);
        }
        //  - RIGHT ROTATION
        if(key > root->left->data){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    // RIGHT -
    if(balance < -1) {
        //  - RIGHT ROTATION
        if(key > root->right->data){
            return leftRotate(root);
        }

        //  - LEFT ROTATION
        if(key < root->right->data){
            root->right = rightRotate((root->right));
            return leftRotate(root);
        }
    }

    return root;
}

void inOrder(struct node *root)
{
    if(root)
    {
        inOrder(root->left);
            cout<< root->data<<" ";
        inOrder(root->right);
    }
}

void preOrder(struct node *root)
{
    if(root != NULL)
    {
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

bool isBalancedUtil(Node root, int *height)
{
    int lh=0;
    int rh=0;
    int l=0,r=0;
    if(root==NULL)
    {
        *height=0;
        return 1;
    }
    l = isBalancedUtil(root->left, &lh);
    r = isBalancedUtil(root->right, &rh);

    *height =(lh>rh? lh : rh) +1;

    if(lh-rh >= 2 || rh-lh>= 2)
        return 0;

    return l&&r;
}

