// http://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct node
{
    int key;
    node *left, *right;
};

typedef  node* Node;

Node newNode(int key)
{
    Node tmp = new node;
    tmp->key = key;
    tmp->left = tmp->right = NULL;
    return tmp;
}

void fooUtil(Node root, int hd, map<int, vector<int>> &m)
{
    if(!root) return;
    m[hd].push_back(root->key);
    fooUtil(root->left, hd-1, m);
    fooUtil(root->right, hd+1, m);
}

void printVerticalOrder(Node root)
{
    map<int, vector<int>> m;
    int hd=0;
    fooUtil(root, 0, m);
    map<int, vector<int>>::iterator map_it;
    vector<int>::iterator v_it;
    for (map_it=m.begin(); map_it!=m.end(); ++map_it)
    {
//        for (int i=0; i<map_it->second.size(); ++i)
//            cout << map_it->second[i] << " ";
        for (v_it = (map_it->second).begin(); v_it!=(map_it->second).end(); ++v_it)
            cout << *v_it << " ";
        cout << endl;
    }
}

int main()
{
    Node root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;
}
