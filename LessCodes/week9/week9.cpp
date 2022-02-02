// week9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "binary_tree.h"

using namespace std;

int main()
{
#if 0 // test 1
    BinaryTreeNode* root = NULL;

    root = new BinaryTreeNode(4);

    root->left = new BinaryTreeNode(6);
    root->right = new BinaryTreeNode(12);

    root->left->left = new BinaryTreeNode(45);
    
    root->right->left = new BinaryTreeNode(7);
    root->right->right = new BinaryTreeNode(1);

    printf("Pre-order Traversal: ");
    PreOrderTraversal(root);
    printf("\n");

    printf("In-order Traversal: ");
    InOrderTraversal(root);
    printf("\n");

    printf("Post-order Traversal: ");
    PostOrderTraversal(root);
    printf("\n");

#elif 0 // test 2
    BinaryTreeNode* root = NULL;

    root = new BinaryTreeNode(1);

    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(4);

    root->left->left = new BinaryTreeNode(3);

    root->right->left = new BinaryTreeNode(5);
    root->right->right = new BinaryTreeNode(7);

    root->right->left->left = new BinaryTreeNode(6);
    root->right->right->right = new BinaryTreeNode(8);

    printf("Pre-order Traversal: ");
    PreOrderTraversal(root);
    printf("\n");

    printf("In-order Traversal: ");
    InOrderTraversal(root);
    printf("\n");

    printf("Post-order Traversal: ");
    PostOrderTraversal(root);
    printf("\n");

#elif 1// test 3
    BinaryTreeNode* root = NULL;

    root = new BinaryTreeNode(1);

    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(4);

    root->left->left = new BinaryTreeNode(3);

    root->right->left = new BinaryTreeNode(5);
    root->right->right = new BinaryTreeNode(7);

    root->right->left->left = new BinaryTreeNode(6);
    root->right->right->right = new BinaryTreeNode(8);

    printf("Pre-order Traversal by a stack: ");
    PreOrderTraversalByStack(root);
    printf("\n");

    printf("Level by level Traversal: ");
    LevelByLevelTraversal(root);
    printf("\n");

#endif


    printf("\n");
    system("pause");
    return 0;
}


