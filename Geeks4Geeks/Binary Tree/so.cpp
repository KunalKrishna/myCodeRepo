// http://stackoverflow.com/questions/29842897/could-you-help-me-in-converting-to-pointer-wherever-used-in-this-binary

#include<iostream>
using namespace std;

struct binaryNode
{
    string data;
    struct binaryNode *left;
    struct binaryNode *right;
};

class binaryTree
{
    private:

    struct binaryNode *root;
    void insert(binaryNode *&root, string value);
    void inorder(binaryNode *&root);
    void levelOrder(binaryNode *&root);
    void deleteEle(binaryNode *&root, string value);
    int height(binaryNode *root);
    bool search(binaryNode *&root, string value);
    string FindMax(binaryNode *root);

    public:

    void inorder();
    void levelOrder();
    void insert(string value);
    void deleteEle(string value);
    bool search(string value);
    int height();
    string FindMax();
    binaryTree();
};

binaryTree::binaryTree()
{
    root=NULL;
}

struct binaryNode* CreateNode(string value)
{
    struct binaryNode *p;
    p=new binaryNode;
    p->data=value;
    p->left=NULL;
    p->right=NULL;
    return p;
}

void binaryTree::insert(string value)
{
    insert(root,value);
}

void binaryTree::insert(binaryNode *&root,string value)
{
    if(root==NULL)
        root = CreateNode(value);
    else if( value > root->data )
        insert (root->right,value);
    else if( value < root->data )
        insert (root->left,value);
}

void binaryTree::inorder()
{
    inorder(root);
}

void binaryTree::inorder(binaryNode *&root)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<" ";
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

string binaryTree::FindMax()
{
    return FindMax(root);
}

string binaryTree::FindMax(binaryNode *root)
{
    struct binaryNode* current;
    current=root;
    while(current->right!=NULL)
        current=current->right;
    return current->data;
}

int binaryTree::height()
{
    return height(root);
}

int max(int a,int b)
{
    if(a >= b)
    return a;
    return b;
}

int binaryTree::height(binaryNode *root)
{
    int y=0,c,d;
    if(root==NULL)
        return 0;
    else
    {
        return max(height(root->left),height(root->right))+1;
    }
}

bool binaryTree::search(string value)
{
    return search(root,value);
}

bool binaryTree::search(binaryNode *&root,string value)
{
    bool status=false;
    if(root==NULL)
        return status;
    if(value<root->data)
        return search(root->left,value);
    if(value>root->data)
        return search(root->right,value);
    if(root->data==value)
    {
        status = true;
    }
    return status;
}

void binaryTree::deleteEle(string value)
{
    deleteEle(root,value);
}

void binaryTree::deleteEle(binaryNode *&root,string value)
{
    if(root==NULL) return;
    if(value < root->data)
    {
        deleteEle(root->left,value);
    }
    else if(value > root->data)
    {
        deleteEle(root->right,value);
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            root=NULL;
            delete root;
        }
        else if(root->left==NULL)
        {
            root=root->right;
        }

        else if(root->right==NULL)
        {
            root=root->left;
        }
        else
        {
            string num;
            num=FindMax(root->left);
            root->data=num;
            deleteEle(root->left,num);
        }
    }
}

void binaryTree::levelOrder()
{
    levelOrder(root);
}

void binaryTree::levelOrder(binaryNode *&root)
{
    if(root==NULL) return;
    queue<binaryNode*> q;
    q.push(root);
    while(!q.empty())
    {
        struct binaryNode *temp;
        temp=q.front();
        cout<<temp->data<<" ";
        if(temp->left!=NULL)q.push(temp->left);
        if(temp->right!=NULL)q.push(temp->right);
        q.pop();
    }
}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<"Size of tree is "<<sizeOfTree(root)<<endl;
    return 0;
}



