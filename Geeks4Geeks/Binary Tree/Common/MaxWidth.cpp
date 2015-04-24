// http://www.geeksforgeeks.org/maximum-width-of-a-binary-tree/

#include<iostream>
#include<climits>
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
int height(struct node* root)
{
//    return (root)? ( 1 + max(height(root->left), height(root->right)))
//                    : 0;
    if(root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int getMax(int* arr, int n)
{
    int max=INT_MIN;
    while(n-1>=0){
        if(arr[n-1]>max)
            max =arr[n-1];
        n--;
    }
    return max;
}

void getMaxWidthRecur(Node root, int*count, int level)
{
    if(root){
        count[level]++;
        getMaxWidthRecur(root->left,count, level+1);
        getMaxWidthRecur(root->right,count, level+1);
    }
}

int getMaxWidth(Node root)
{
    int h = height(root);
    int max_width;
    int* count = new int [h];
    for(int i=0; i<h; i++)
        count[i]=0;
    getMaxWidthRecur(root, count, 0);
    max_width = getMax(count, h);
    delete [] count;
    return max_width;
}

int main(){

    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->right = newNode(8);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);

    cout<<"Max width of tree(at any level) is "<< getMaxWidth(root) <<endl;

    return 0;
}
