#ifndef BST_H
#define BST_H

// Node structure
typedef struct Node
{
    char data;
	struct Node* left;//pointer to the left child node
	struct Node* right;//pointer to the right child node
} Node;

// Function prototypes
Node* insert(Node* root, char value);//node used for inserting a new node into the BST

Node* search(Node* root, char value);//searches for a node with the given value in the BST

void inorder(Node* root);//performs an inorder traversal of the BST and prints the values of the nodes

int countNodes(Node* root);//counts the number of nodes in the BST

int treeHeight(Node* root);//calculates the height of the BST

#endif