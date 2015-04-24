// http://www.geeksforgeeks.org/add-greater-values-every-node-given-bst/
// http://www.geeksforgeeks.org/convert-bst-to-a-binary-tree/

#include<iostream>
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

void inOrder(struct node* root)
{
    if(root){
        inOrder(root->left);
            cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int sizeOfTree(struct node* root)
{
    if(root == NULL){
        return 0;
    }
    return sizeOfTree(root->left)+1+sizeOfTree(root->right);
}

void insertNode(Node &root, int key)
{
    if(root == NULL)
        root = newNode(key);
    else{
        if(root->data > key)
            insertNode(root->left, key);
        else
            insertNode(root->right, key);
    }
}

void modifyBSTUtil(Node root, int &sum)
{
    if(root)
    {
        modifyBSTUtil(root->right, sum);

        root->data += sum;
        sum = root->data;

        modifyBSTUtil(root->left, sum);
    }
}

void modifyBST(Node root)
{
    int sum =0;
    modifyBSTUtil(root, sum);
}

int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    inOrder(root);
    cout<<endl;
    modifyBST(root);

    // print inoder tarversal of the modified BST
    inOrder(root);

    return 0;
}
