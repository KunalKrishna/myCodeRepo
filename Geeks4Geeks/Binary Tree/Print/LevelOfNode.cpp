// http://www.geeksforgeeks.org/get-level-of-a-node-in-a-binary-tree/

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

int getLevelUtil(struct node* root,int key, int level)
{
    if(root == NULL)
        return 0;
    if(root->data == key)
        return level;

    int downLevel = getLevelUtil(root->left, key, level+1);
    if(downLevel)
        return downLevel;
    return getLevelUtil(root->right, key, level+1);
}
// g4g method
int getLevel(struct node* root,int key)
{
    return getLevelUtil(root, key, 1);
}

// my method
bool getLevel2(Node root, int target, int *lvl)
{
    if(root == NULL)
        return false;
    if(root->data ==  target){
        *lvl = 1;
        return true;
    }

    if(getLevel2(root->left, target, lvl) || getLevel2(root->right, target, lvl))
    {
        *lvl +=1;
        return true;
    }
    return false;
}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    for (int x = 0; x <8; x++)
    {
      int level = getLevel(root, x);
      if (level)
        cout<<"Level of "<< x<<" = "<<level<<endl;
      else
        cout<<x<<" is not present in tree "<<endl;
    }

    cout<<endl;
    for(int key = 0; key<8; key++){
        int lvl =0;
        if(getLevel2(root, key, &lvl )){
            cout<<"Level of "<<key<<" is "<<lvl<<endl;
        } else{
            cout<<key<<" doesnt exist in tree"<<endl;;
        }
    }


    return 0;
}
