// http://www.geeksforgeeks.org/find-the-minimum-element-in-a-binary-search-tree/

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

void findPreSuc(Node root, Node &pre, Node &suc, int key)
{
    if(root == NULL) return;
    int current_data = root->data;

    if( current_data== key){

        if(root->left != NULL){
            Node temp = root->left;
            while(temp->right)
                temp= temp->right;
            pre = temp;
        }

        if(root->right != NULL){
            Node temp = root->right;
            while(temp->left)
                temp= temp->left;
            suc = temp;
        }
        return;
    }

    if(current_data < key){
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    if(current_data > key){
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
}

int main()
{
    struct node* root = NULL;
    insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 0);
    insertNode(root, 20);
    insertNode(root, 1);

    inOrder(root);

    int key=20;
    Node pre=NULL;
    Node suc=NULL;
    findPreSuc(root, pre, suc, key);
    if(pre){
        cout<< "\nPredecessor is "<< pre->data <<endl;
    } else {
        cout<< "\n No Predecessor " <<endl;
    }
    if(suc){
        cout<< "\nSuccessor is "<< suc->data <<endl;
    } else {
        cout<< "\n No Successor " <<endl;
    }

    return 0;
}
