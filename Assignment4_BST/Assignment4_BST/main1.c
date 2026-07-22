#include <stdio.h>      // Standard input/output library
#include <stdlib.h>     // Standard library for rand(), srand(), and NULL
#include <time.h>       // Time library for time()
#include "bst1.h"       // Header file containing the BST functions

// Main function where the program starts
int main()
{
    // Create an empty Binary Search Tree
    Node* root = NULL;

    // Seed the random number generator using the current time
    srand((unsigned int)time(NULL));

    // Generate a random number between 11 and 20 (inclusive)
    int numChars = rand() % 10 + 11;

    // Display a heading for the inserted characters
    printf("Characters inserted:\n");

    // Loop to generate and insert random characters
    for (int i = 0; i < numChars; i++)
    {
        // Generate a random lowercase letter from 'a' to 'z'
        char randomChar = 'a' + rand() % 26;

        // Print the generated character
        printf("%c ", randomChar);

        // Insert the character into the Binary Search Tree
        root = insert(root, randomChar);
    }

    // Print two blank lines for better formatting
    printf("\n\n");

    // Display a heading for the sorted characters
    printf("Characters in alphabetical order:\n");

    // Print the characters in alphabetical order using inorder traversal
    inorder(root);

    // Print two blank lines for better formatting
    printf("\n\n");

    // Display the total number of nodes in the tree
    printf("Number of nodes: %d\n", countNodes(root));

    // Display the height of the tree
    printf("Tree height: %d\n", treeHeight(root));

    // Character to search for in the tree
    char searchChar = 'm';

    // Check whether the character exists in the tree
    if (search(root, searchChar) != NULL)
    {
        // Print this message if the character is found
        printf("Character '%c' found in the tree.\n", searchChar);
    }
    else
    {
        // Print this message if the character is not found
        printf("Character '%c' not found in the tree.\n", searchChar);
    }

    return 0;
}