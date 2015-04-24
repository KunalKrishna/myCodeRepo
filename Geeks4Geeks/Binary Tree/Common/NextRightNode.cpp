// http://www.geeksforgeeks.org/find-next-right-node-of-a-given-key/

#include<iostream>
#include<queue>
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

Node nextRight(Node root, int key)
{
    if(!root) return root;

    queue<Node> qn;
    queue<int> ql;

    qn.push(root);
    ql.push(0);

    while(qn.size())
    {
        Node n = qn.front();
        int lvl = ql.front();
        qn.pop();
        ql.pop();

        if(n->data == key){
            if(qn.size() == 0 || ql.front() != lvl)
                return NULL;
            return qn.front();
        }
        if(n->left){
            qn.push(n->left);
            ql.push(lvl+1);
        }
        if(n->right){
            qn.push(n->right);
            ql.push(lvl+1);
        }
    }
    return NULL;
}


int main(){

    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    Node next = NULL;
    for(int key = 1; key<6; key++){
        next = nextRight(root, key);
        if(next) {
            cout<<" Next right to "<<key<<" -> "<<next->data<<endl;
        } else {
            cout<<" No next right node to "<<key<<endl;
        }
    }

    return 0;
}
