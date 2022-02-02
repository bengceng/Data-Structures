#pragma once
#include <stack>
#include <queue>

using namespace std;

struct BinaryTreeNode {
	BinaryTreeNode* left;
	int key;
	BinaryTreeNode* right;

	//Constructor
	BinaryTreeNode(int key) {
		this->key = key;
		this->left = this->right = NULL;
	}
};


// Traversal Approaches
// Pre-Order Traversal
void PreOrderTraversal(BinaryTreeNode* root) {
	if (root == NULL) return;
	printf("%d, ", root->key);
	PreOrderTraversal(root->left);
	PreOrderTraversal(root->right);
}

// In-Order Traversal
void InOrderTraversal(BinaryTreeNode* root) {
	if (root == NULL) return;	
	InOrderTraversal(root->left);
	printf("%d, ", root->key);
	InOrderTraversal(root->right);
}

// Post-Order Traversal
void PostOrderTraversal(BinaryTreeNode* root) {
	if (root == NULL) return;	
	PostOrderTraversal(root->left);
	PostOrderTraversal(root->right);
	printf("%d, ", root->key);
}

// Pre-Order Traversal by a Stack
// a.k.a. depth-first search
void PreOrderTraversalByStack(BinaryTreeNode* root) {
	if (root == NULL) return;

	stack <BinaryTreeNode*> S;
	S.push(root);

	while (!S.empty()) {
		BinaryTreeNode* p = S.top();
		S.pop();
		printf("%d, ", p->key);

		if (p->right != NULL) S.push(p->right);
		if (p->left != NULL) S.push(p->left);
	}
}
// Level by Level Traversal using a Queue
// a.k.a. breath-first search
void LevelByLevelTraversal(BinaryTreeNode* root) {
	if (root == NULL) return;

	queue <BinaryTreeNode*> Q;
	Q.push(root);

	while (!Q.empty()) {
		BinaryTreeNode* p = Q.front();
		Q.pop();
		printf("%d, ", p->key);

		if (p->left != NULL) Q.push(p->left);
		if (p->right != NULL) Q.push(p->right);
	}
}