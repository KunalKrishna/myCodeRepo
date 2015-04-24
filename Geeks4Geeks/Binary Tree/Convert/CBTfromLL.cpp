// http://www.geeksforgeeks.org/given-linked-list-representation-of-complete-tree-convert-it-to-linked-representation/

#include<iostream>
#include<queue>

using namespace std;

struct ListNode{
    int data;
    ListNode* next;
};

struct BTnode{
    int data;
    BTnode* left;
    BTnode* right;
};

typedef struct BTnode* BTNode;
typedef struct BTnode** BTNodeRef;

void push( ListNode **head_ref, int data)
{
    ListNode* temp = new ListNode;
    temp->data = data;
    temp->next = *head_ref;
    *head_ref = temp;
}

struct BTnode* newBTNode(int newData)
{
    struct BTnode* newNode = new BTnode;
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrder(struct BTnode* root)
{
    if(!root){
        inOrder(root->left);
            cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void convertList2Binary(ListNode* head, BTNode &root)
{
    if(head == NULL){
        root = NULL;
        return;
    }

    queue<BTNode> qTree;
    root = newBTNode(head->data);
    qTree.push(root);
    head = head->next;

    while(head){
        BTNode parent = qTree.front();
        qTree.pop();

        BTNode leftTree = NULL, rightTree = NULL;

        leftTree = newBTNode(head->data);
        head = head->next;
        qTree.push(leftTree);
        if(head){
            rightTree = newBTNode(head->data);
            head = head->next;
            qTree.push(rightTree);
        }
        parent->left = leftTree;
        parent->right = rightTree;
    }
}

int main()
{
    struct ListNode* head = NULL;
    push(&head, 36);  /* Last node of Linked List */
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10); /* First node of Linked List */

    BTNode root;
    convertList2Binary(head, root);

    cout << "Inorder Traversal of the constructed Binary Tree is: \n";
    inOrder(root);
    return 0;

}
