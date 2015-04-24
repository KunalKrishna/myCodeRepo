//http://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/

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
    node* newNode = new node;
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool areIdenticalTrees(struct node* tree1, struct node* tree2)
{
    // both subtree NULL
    if(tree1 == NULL && tree2 == NULL){
        return true;
    }
    // both tree not NULL
    if(tree1 != NULL && tree2 !=NULL){
        return
        (
            tree1->data == tree2->data
            && areIdenticalTrees(tree1->left ,tree2->left )
            && areIdenticalTrees(tree1->right,tree2->right)
        );
    }
    return false;
}

int main()
{
    struct node *root1 = newNode(1);
    struct node *root2 = newNode(1);

    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5);

    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    if(areIdenticalTrees(root1, root2))
        cout<<"Both trees are identical.";
    else
        cout<<"Trees are NOT identical.";

    return 0;
}
