// http://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/

#include<iostream>
#include<vector>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

typedef struct node* Node;
typedef struct node** NodeRef;

Node newNode(int newData)
{
    Node newNode = new node;
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrder(Node root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
    cout<<root->data;
    inOrder(root->right);
}

bool findPath(Node root, vector<int> &path, int key)
{
    if(!root) return false;
    path.push_back(root->data);

    if(root->data == key)
        return true;

    if( root->left && findPath(root->left, path, key) ||
       root->right && findPath(root->right, path, key) )
        return true;
    path.pop_back();
    return false;
}

int findLCA(Node root, int n1, int n2)
{
    if(root == NULL)
        return -1;
    vector<int> path1, path2;

    if( !findPath(root, path1, n1) ||
       !findPath(root, path2, n2) )
       return -1;

    int i=0;
    for( ; i<path1.size() && i<path2.size(); i++){
        if(path1[i] != path2[i]){
            break;
        }
    }
    return path1[i-1];
}

Node findLCAOpt(Node root, int n1, int n2)
{
    if(!root) return root;

    if(root->data == n1 || root->data == n2)
        return root;

    Node left_LCA  = findLCAOpt(root->left, n1, n2);
    Node right_LCA = findLCAOpt(root->right, n1, n2);

    if( left_LCA && right_LCA)
        return root;

    return (left_LCA !=NULL )?left_LCA:right_LCA;
}

int main(){

    Node root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = "   << findLCA(root, 4, 5);
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);

    cout << "\n---\n";
    cout << "LCA(4, 5) = "   << findLCAOpt(root, 4, 5)->data;
    cout << "\nLCA(4, 6) = " << findLCAOpt(root, 4, 6)->data;
    cout << "\nLCA(3, 4) = " << findLCAOpt(root, 3, 4)->data;
    cout << "\nLCA(2, 4) = " << findLCAOpt(root, 2, 4)->data;

    return 0;
}
