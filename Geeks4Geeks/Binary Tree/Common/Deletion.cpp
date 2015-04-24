// http://www.geeksforgeeks.org/write-a-c-program-to-delete-a-tree/

#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

struct node* newNode(int newData)
{
    struct node* newNode = new node;
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int sizeOfTree(struct node* root)
{
    if(root == NULL){
        return 0;
    }
    return sizeOfTree(root->left)+1+sizeOfTree(root->right);
}

void postOrder(struct node* root)
{
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

/*  postorder deletion */
void _deleteTree(struct node* node)
{
    if (node == NULL) return;

    /* first delete both subtrees */
    _deleteTree(node->left);
    _deleteTree(node->right);

    /* then delete the node */
    cout<<"\n Deleting node: "<<node->data;
    delete(node);
}

/* Deletes a tree and sets the root as NULL */
void deleteTree(struct node** node_ref)
{
  _deleteTree(*node_ref);
  *node_ref = NULL;
}


int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    postOrder(root);
    cout<<"\nSize of tree is "<<sizeOfTree(root)<<endl;
    deleteTree(&root);
    cout<<"\n\nSize of tree after deletion "<<sizeOfTree(root)<<endl;
    return 0;
}
