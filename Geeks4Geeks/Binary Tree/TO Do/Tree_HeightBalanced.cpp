// http://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/

#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node{

    int data;
    node* left;
    node* right;
};
typedef struct node* Node;
typedef struct node** NodeRef;

struct node* newNode(int newData){

    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void inOrder(struct node* root){

    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

int sizeOfTree(struct node* root){

    if(root == NULL){
        return 0;
    }
    return sizeOfTree(root->left)+1+sizeOfTree(root->right);
}

int maxDepth(struct node* root){

    int max = 0;
    if(root == NULL)
        return 0;
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    max = (leftHeight > rightHeight) ? leftHeight : rightHeight;
    return 1+max;
}

bool isBalanced(Node tree){

    if( tree == NULL)
        return true;

    int lHeight = maxDepth(tree->left);
    int rHeight = maxDepth(tree->right);

    if(abs(lHeight-rHeight)<=1){
        return isBalanced(tree->left) && isBalanced(tree->right);
    }
    return false;
}

/* WONT WORK
bool isBalanced2(Node tree){

    if( tree == NULL)
        return true;

    return isBalanced2(tree->left) && isBalanced2(tree->right);

    int lHeight = maxDepth(tree->left);
    int rHeight = maxDepth(tree->right);

    if(abs(lHeight-rHeight)<=1){
        return true;
    }else{
        return false;
    }
}*/
//optimised version
bool isBalanceOpt(){


}

int main(){

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);

    if(isBalanced(root))
      printf("Tree is balanced");
    else
      printf("Tree is not balanced");

    printf("\n\nSize of tree is %d \n", sizeOfTree(root));
    getchar();
}
