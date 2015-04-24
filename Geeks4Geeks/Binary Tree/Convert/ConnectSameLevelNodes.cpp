// http://www.geeksforgeeks.org/connect-nodes-at-same-level/
// http://www.geeksforgeeks.org/connect-nodes-at-same-level-with-o1-extra-space/

#include<iostream>
#include<queue>

using namespace std

struct BTnode{
    int data;
    BTnode* left;
    BTnode* right;
};

typedef struct BTnode* BTNode;
typedef struct BTnode** BTNodeRef;

struct BTnode* newBTNode(int newData)
{
    struct BTnode* newNode = new BTnode;
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrder(struct BTnode* root)
{
    if(!root){
        inOrder(root->left);
            cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void connect(){}
int main()
{

    return 0;

}
