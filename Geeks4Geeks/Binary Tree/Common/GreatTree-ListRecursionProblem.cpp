// http://cslibrary.stanford.edu/109/TreeListRecursion.html#c

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

Node newNode(int newData)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data  = newData;
    newNode->left  = NULL;
    newNode->right = NULL;
    return newNode;
}

void treeInsert(NodeRef rootRef, int data)
{
	Node root = *rootRef;
	if(root	 == NULL) {
		*rootRef = newNode(data);
	}
	else {
		if(data >= root->data) treeInsert( &(root->right), data);
		else treeInsert( &(root->left), data);
	}
}
// a + b
void inOrder(Node root){

    if(root == NULL) return;

    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

void printList(Node head) {
    Node current = head;

    while(current != NULL) {
        printf("%d ", current->data);
        current = current->right;
        if (current == head) break;
    }
    printf("\n");
}

void join(Node a, Node b){
	a->right = b;
	b->left  = a;
}

Node append(Node a, Node b){
	Node aLast, bLast;

	if(a==NULL) return(b);
	if(b==NULL) return(a);

	aLast = a->left;
	bLast = b->left;

	//aLast->right = b;
	//b->left= aLast;
	join(aLast, b);

	//bLast->right=a;
	//a->left = bLast;
	join(bLast, a);

	return a;
}

Node treeToList(Node root){
	if (root == NULL) return (NULL);

	Node aList = treeToList(root->left);
	Node bList = treeToList(root->right);

	root->left = root;
	root->right= root;

	aList = append(aList, root);
	aList = append(aList, bList);;

	return (aList);
}

int main(){

    Node root = NULL;

	treeInsert(&root, 10);
    treeInsert(&root, 5);
    treeInsert(&root, 15);
    treeInsert(&root, 1);
    treeInsert(&root, 2);

	printf("BST inOder traversal : ");
	inOrder(root);

	Node head = treeToList(root);

	printf("\nDoubly linked list :");
	printList(head);

    return 0;
}
