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

