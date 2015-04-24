// http://www.geeksforgeeks.org/level-order-tree-traversal/
// http://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/

#include<iostream>
#include <stack>
#include <queue>

using namespace std;

struct node{

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

int maxDepth(struct node* root)
{
    int max = 0;
    if(root == NULL)
        return 0;
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    max = (leftHeight > rightHeight) ? leftHeight : rightHeight;
    return 1+max;
}

// a + b
void inOrder(struct node* root)
{
    if(!root){
        inOrder(root->left);
        cout<<root->data;
        inOrder(root->right);
    }
}

// + a b
void preOrder(struct node* root)
{
    if(!root){
        cout<<root->data;
        preOrder(root->left);
        preOrder(root->right);
    }
}

// a b +
void postOrder(struct node* root)
{
    if(!root){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data;
    }
}





// http://www.geeksforgeeks.org/level-order-tree-traversal/
void printGivenLevel(struct node* root, int level);
void levelOrder(struct node* tree)
{
    int height = maxDepth(tree);
    for(int h=1; h <= height; h++)
    {
        printGivenLevel(tree, h);
    }
}

void printGivenLevel(struct node* root, int level)
{
    if(root != NULL){
        if(level == 1){
            cout<<root->data<<" ";
        } else if(level > 1){
            printGivenLevel(root->left, level-1);
            printGivenLevel(root->right, level-1);
        }
    }
}

void levelOrderUsingQueue(Node root)
{
    Node temp;
    queue<Node> q;
    if(!root) return;

    q.push(root);
    while(!q.empty() )
    {
        temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left);
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

// http://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/
void printGivenLevelSpiral(struct node* root, int level, bool direction);
void printSpiral(struct node* tree)
{
    int height = maxDepth(tree);
    bool direction =false;
    for(int h=1; h <= height; h++){
        printGivenLevelSpiral(tree, h, direction);
        direction = !direction;

    }
}

void printGivenLevelSpiral(struct node* root, int level, bool direction)
{
    if(root != NULL){
        if(level == 1){
            cout<<root->data<<" ";
        } else if(level > 1){
            if(direction){
                printGivenLevelSpiral(root->left,  level-1, direction);
                printGivenLevelSpiral(root->right, level-1, direction);
            }else {
                printGivenLevelSpiral(root->right, level-1, direction);
                printGivenLevelSpiral(root->left,  level-1, direction);
            }
        }
    }
}


void printSpiralUsingStack(struct node* root)
{
    stack<struct node*> st1, st2;
    Node temp;

    if(root == NULL) return;
    //else
    st1.push(root);

    while(!st1.empty() || !st2.empty() )
    {
        while(!st1.empty() ){
            temp = st1.top(); st1.pop();
            cout<<temp->data<<" ";

            if(temp->left)
                st2.push(temp->right);
            if(temp->right)
                st2.push(temp->left);
        }
        while(!st2.empty() ){
            temp = st2.top(); st2.pop();
            cout<<temp->data<<" ";

            if(temp->left)
                st1.push(temp->left);
            if(temp->right)
                st1.push(temp->right);
        }
    }
}



int main(){

//    struct node* root = newNode(1);
//    root->left = newNode(2);
//    root->right = newNode(3);
//    root->left->left = newNode(4);
//    root->left->right = newNode(5);
//    root->right->left = newNode(6);
//    root->right->right = newNode(7);
//    root->left->left->left = newNode(8);
//    root->left->left->right = newNode(9);

    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);

    cout<<"\nLevel Order traversal of tree : \n";
    levelOrder(root);

    cout<<"\nLevel Order traversal of tree using Queue: \n";
    levelOrderUsingQueue(root);

    cout<<"\n\nSpiral Level Order traversal of tree(Method 1 ) : \n";
    printSpiral(root);

    cout<<"\n\nSpiral Level Order traversal of tree(Method 2 Using Stack) : \n";
    printSpiralUsingStack(root);

    cout<<endl;
    return 0;
}
