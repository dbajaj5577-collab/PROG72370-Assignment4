#include <stdio.h>
#include <stdlib.h>
#include "bst1.h"

// Insert a new node into the Binary Search Tree
Node* insert(Node* root, char value)

{
    if (root == NULL) //if the root is null then create a new node and return newnode
    {
		Node* newNode = (Node*)malloc(sizeof(Node));//allocating size of the node to newNode
        if (newNode == NULL) {
            return NULL; //error handling if the newnode is null or not
        }
		newNode->data = value; //assigning the value to the newNode
		newNode->left = NULL; //assigning the left and right child to null
		newNode->right = NULL; //assigning the left and right child to null
		return newNode; //returning the newNode
    }

    if (value < root->data) //if value is less than data
    {
        root->left = insert(root->left, value);//inserting value at left 
    }
    else// or else
    {
        root->right = insert(root->right, value);//inserting value at right
    }

    return root;
}

// function to search character from the binary search tree 
Node* search(Node* root, char value) 
{
    if (root == NULL) // if tree is empty then it will return NULL
    {
        return NULL;
    }

    if (root->data == value) // if the current node contains the value then it will return node
    {
        return root; 
    }

    if (value < root->data) // if value is less than the current node and it will continue search in the left subtree
    {
        return search(root->left, value);
    }

    return search(root->right, value); // if not found in the left subtree, it will search in the right subtree.
}

// Function to print the tree in alphabetical order
void inorder(Node* root)
{
    if (root != NULL) // it checks if the current node is not NULL
    {
        inorder(root->left); // first goes to the left subtree
        printf("%c ", root->data); // it prints the data stored in the current node
        inorder(root->right); // then goes to the right subtree
    }
}

// Function to count the total number of nodes
int countNodes(Node* root)
{
    if (root == NULL) // check if the current node is NULL
    {
        return 0; // if the node is NULL then it will return 0
    }

    return 1 + countNodes(root->left) + countNodes(root->right); // counts the current node and then counts the nodes in the left and right subtree, recursively.
}

// Function to determine the height of the tree
int treeHeight(Node* root)
{
    if (root == NULL) // check if the current node is NULL
    {
        return -1; // it returns -1 because -1 is the height of BST when it is empty
    }

    int leftHeight = treeHeight(root->left); // calculate the height of left subtree
    int rightHeight = treeHeight(root->right); // calculates the height of the right subtree

    if (leftHeight > rightHeight) // check if height of left subtree is greater than right subtree
    {
        return leftHeight + 1; // if it is greater than right subtree, then it will return height +1
    }

    return rightHeight + 1; // else it will return right subtree height +1
}