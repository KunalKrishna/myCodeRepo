// http://www.geeksforgeeks.org/check-binary-tree-subtree-another-binary-tree-set-2/

#include<iostream>
#include<climits>
#include<cstring>
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

void storeInorder(Node root, char * inArr, int &i)
{
    if(root == NULL){
        inArr[i++] = '$';
        return;
    }

    storeInorder(root->left, inArr, i);
    inArr[i++] = root->data;
    storeInorder(root->right, inArr, i);
}

void storePreorder(Node root, char * preArr, int &i)
{
    if(root == NULL){
        preArr[i++] = '$';
        return;
    }
    preArr[i++] = root->data;
    storePreorder(root->left, preArr, i);
    storePreorder(root->right, preArr, i);
}

bool isSubtree(Node T, Node S)
{
    if(!T && !S)    return true;
    if(!T || !S)    return false;

    char inT[100], inS[100];
    int i = 0;
    storeInorder(T, inT, i);
    inT[i]='\0';
    i=0;
    storeInorder(S, inS, i);
    inS[i]='\0';
    i=0;

    if(strstr(inT,inS) == NULL)
        return false;

    char preT[100], preS[100];

    storePreorder(T, preT, i);
    preT[i]='\0';
    i=0;
    storePreorder(S, preS, i);
    preS[i]='\0';

    return (strstr(preT,preS) != NULL);

}

int main()
{
    Node T = newNode('a');
    T->left = newNode('b');
    T->right = newNode('d');
    T->left->left = newNode('c');
    T->right->right = newNode('e');
    /*
          a
        /  \
       b    d
      / \
     c   e

    */


    Node S = newNode('a');
    S->left = newNode('b');
    S->left->left = newNode('c');
    S->right = newNode('d');

    /*
          a
        /  \
       b    d
      /
     c

    */

    if (isSubtree(T, S))
        cout << "Yes: S is a subtree of T";
    else
        cout << "No: S is NOT a subtree of T";

    return 0;
}
