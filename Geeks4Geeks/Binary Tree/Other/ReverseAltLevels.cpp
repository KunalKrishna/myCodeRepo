// http://www.geeksforgeeks.org/reverse-alternate-levels-binary-tree/

#include<iostream>
#define MAX_SIZE 100;
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
    //struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* newNode = new node;
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void reverseArray(char arr[],int n)
{
    int i=0;
    int j=n-1;
    char tmp;
    while(i<j){
        tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
        i++; j--;
    }
}

void storeElementAtOddLevel(Node root, int lvl, char holder[], int *size)
{
    if(root==NULL) return;
    storeElementAtOddLevel(root->left,  lvl+1, holder, size);
    if(lvl%2 == 1){
        holder[(*size)++] = root->data;
    }
    storeElementAtOddLevel(root->right, lvl+1, holder, size);

}

void modifyTree(Node root, int lvl, char order[], int *i, int size)
{
    if(!root) return;
    modifyTree(root->left, lvl+1, order, i, size);
    if(lvl%2==1){
        if(*i<size)
        root->data = order[(*i)++];
    }
    modifyTree(root->right, lvl+1, order, i, size);
}

void reverseAlternate(Node root)
{
    if(!root) return;
    char oddLevelElt[100];
    int size=0;

    storeElementAtOddLevel(root,0, oddLevelElt, &size );
    cout<<endl;
    reverseArray(oddLevelElt, size);
    int index =0;
    modifyTree(root, 0, oddLevelElt, &index, size);
}

void inOrder(struct node* root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
        cout<<root->data<<" ";
    inOrder(root->right);
}

int main()
{
    struct node *root = newNode('a');
    root->left = newNode('b');
    root->right = newNode('c');
    root->left->left = newNode('d');
    root->left->right = newNode('e');
    root->right->left = newNode('f');
    root->right->right = newNode('g');
    root->left->left->left = newNode('h');
    root->left->left->right = newNode('i');
    root->left->right->left = newNode('j');
    root->left->right->right = newNode('k');
    root->right->left->left = newNode('l');
    root->right->left->right = newNode('m');
    root->right->right->left = newNode('n');
    root->right->right->right = newNode('o');

    cout << "Inorder Traversal of given tree\n";
    inOrder(root);

    reverseAlternate(root);
//
    cout << "\n\nInorder Traversal of modified tree\n";
    inOrder(root);

    return 0;
}
