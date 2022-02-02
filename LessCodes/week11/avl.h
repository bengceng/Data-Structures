#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct AVLNode {
	int key;
	int height;
	AVLNode* left, * right;
	AVLNode(int key) { this->key = key; left = right = NULL; height = 0; }
};

class AVL {
private:
	AVLNode* root;

	void printAux(AVLNode* node);
	void LevelValues(AVLNode* node);
	void deleteTreeNodes(AVLNode* node);
	void balance(stack<AVLNode*>& S);

public:
	AVL() { root = NULL; }
	~AVL() { deleteTreeNodes(root); root = NULL; }
	bool find(int key);
	int min();
	int max();
	void add(int key);
	void remove(int key);
	void print();
	void printLevelByLevel();
};

// Delete all nodes in the tree
void AVL::deleteTreeNodes(AVLNode* node) {
	if (node == NULL) return;
	deleteTreeNodes(root->left);
	deleteTreeNodes(root->right);
	delete root;
	root = NULL;
}


// Checks if the given key exists in the tree
bool AVL::find(int key) {
	AVLNode* p = root;

	while (p) {
		if (key == p->key) return true;
		if (key < p->key) p = p->left;
		else			  p = p->right;
	}
	return false;
}

// Returns minimum key in the AVL
int AVL::min() {
	if (root == NULL) throw std::exception("AVL::min - Tree is empty");

	AVLNode* p = root;
	while (p->left != NULL) p = p->left;

	return p->key;
}

// Returns maximum key in the AVL
int AVL::max() {
	if (root == NULL) throw std::exception("AVL::max - Tree is empty");

	AVLNode* p = root;
	while (p->right != NULL) p = p->right;

	return p->key;
}

// A macro to get the height of a node
#define Height(p) ((p) == NULL? -1:(p)->height)

// After add and delete operations rebalance the AVL tree
void AVL::balance(stack<AVLNode*>& S) {
	while (!S.empty()) {
		AVLNode* p = S.top(); S.pop();

		int hl = Height(p->left);
		int hr = Height(p->right);
		p->height = 1 + std::max(hl, hr);

		int bf = hl - hr;
		if (bf >= -1 && bf <= 1) continue;

		// p is the pivot. Rotate.
		AVLNode* pp = NULL;
		if (!S.empty()) pp = S.top();

		if (bf == 2) {
			// Height of the left subtree is bigger
			AVLNode* l = p->left;

			hl = Height(l->left);
			hr = Height(l->right);
			bf = hl - hr;

			if (bf == 0 || bf == 1) {
				// LL imbalance. Rotate once
				p->left = l->right;
				l->right = p;

				p->height = 1 + std::max(Height(p->left), Height(p->right));
				l->height = 1 + std::max(Height(l->left), Height(l->right));

				if (pp == NULL) root = l;
				else {
					if (p == pp->left) pp->left = l;
					else			   pp->right = l;
				}

			}
			else {
				// LR imbalance. Rotate twice
				AVLNode* x = l->right;

				l->right = x->left;
				x->left = l;

				p->left = x->right;
				x->right = p;

				p->height = 1 + std::max(Height(p->left), Height(p->right));
				l->height = 1 + std::max(Height(l->left), Height(l->right));
				x->height = 1 + std::max(Height(x->left), Height(x->right));

				if (pp == NULL) root = x;
				else {
					if (p == pp->left) pp->left = x;
					else               pp->right = x;
				}
			}
		}
		else {
			// bf == -2 
			// Height of the right subtree is bigger
			AVLNode* r = p->right;

			hl = Height(r->left);
			hr = Height(r->right);
			bf = hl - hr;

			if (bf == 0 || bf == -1) {
				// RR imbalance. Rotate once.
				p->right = r->left;
				r->left = p;

				p->height = 1 + std::max(Height(p->left), Height(p->right));
				r->height = 1 + std::max(Height(r->left), Height(r->right));

				if (pp == NULL) root = r;
				else {
					if (p == pp->left) pp->left = r;
					else               pp->right = r;
				}
			}
			else {
				// RL imbalance. Rotate twice
				AVLNode* x = r->left;

				r->left = x->right;
				x->right = r;

				p->right = x->left;
				x->left = p;

				p->height = 1 + std::max(Height(p->left), Height(p->right));
				r->height = 1 + std::max(Height(r->left), Height(r->right));
				x->height = 1 + std::max(Height(x->left), Height(x->right));

				if (pp == NULL) root = x;
				else {
					if (p == pp->left) pp->left = x;
					else               pp->right = x;
				}
			}
		}
	}
}

// Adds new item to the tree
void AVL::add(int key) {
	stack <AVLNode*> S;
	
	AVLNode* q = NULL;
	AVLNode* p = root;
	while (p) {
		S.push(p);

		q = p;
		if (p->key == key) { return; }
		else if (key < p->key) { p = p->left; }
		else { p = p->right; }
	}

	AVLNode* node = new AVLNode(key);
	if (root == NULL) root = node;
	else if (key < q->key) q->left = node;
	else q->right = node;

	// Balance the tree (if necessary)
	balance(S);

}

// Removes a given key from the AVL
void AVL::remove(int key) {
	stack <AVLNode*> S;
	
	AVLNode* pp = NULL;
	AVLNode* p = root;

	while (p && p->key != key) {
		S.push(p);
		pp = p;
		if (key < p->key) p = p->left;
		else			  p = p->right;
	}

	// Key does not exist
	if (p == NULL) return;

	// Node has 2 children
	if (p->left && p->right) {
		S.push(p);
		AVLNode* qp = p;
		AVLNode* q = p->left;

		while (q->right) {
			S.push(q);
			qp = q;
			q = q->right;
		}

		p->key = q->key;
		pp = qp;
		p = q;
	}
	// SC: Tree with a single root node
	if (p == root) {
		root = root->left ? root->left : root->right;
		delete p;
		return;
	}
	
	// SC
	if (p == pp->left) pp->left = p->left ? p->left : p->right;
	else			   pp->right = p->left ? p->left : p->right;
	
	delete p;

	// Balance the tree (if necessary)
	balance(S);

}

// In-Order Traversal
void AVL::printAux(AVLNode* root) {
	if (root == NULL) return;
	printAux(root->left);
	printf("%d, ", root->key);
	printAux(root->right);
}

void AVL::print() {
	std::cout << "AVL Keys: ";
	printAux(root);
	std::cout << std::endl;
}


void AVL::LevelValues(AVLNode* root) {
	if (root == NULL) return;

	// <node, level>
	queue<pair<AVLNode*, int>> Q;
	int currentLevel = 0;
	Q.push(make_pair(root, currentLevel));

	printf("Level[%d]: ", currentLevel);

	while (!Q.empty()) {
		AVLNode *p = Q.front().first;
		int level = Q.front().second;

		Q.pop();

		// Level check
		if (level > currentLevel) {
			currentLevel = level;
			printf("\n");
			printf("Level[%d]: ", currentLevel);
		}

		printf("%d ", p->key);

		if (p->left) Q.push(make_pair(p->left, level + 1));
		if (p->right) Q.push(make_pair(p->right, level + 1));
	}
}

void AVL::printLevelByLevel() {
	LevelValues(root);
	std::cout << std::endl;

}