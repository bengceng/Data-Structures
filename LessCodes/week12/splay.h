#pragma once
#include <stack>
#include <queue>

using namespace std;

struct BSTNode {
	int key;
	BSTNode* left, * right;
	BSTNode(int key) { this->key = key; left = right = NULL; }
};

class BST {
private:
	BSTNode* root;

	void printAux(BSTNode* node);
	void deleteTreeNodes(BSTNode* node);
	void LevelValues(BSTNode* node);
	void splay(stack<BSTNode*>& S);

public:
	BST() { root = NULL; }
	~BST() { deleteTreeNodes(root); root = NULL; }
	bool find(int key);
	int min();
	int max();
	void add(int key);
	void remove(int key);
	void print();
	void printLevelByLevel();
};

// Delete all nodes in the tree
void BST::deleteTreeNodes(BSTNode* node) {
	if (node == NULL) return;
	deleteTreeNodes(root->left);
	deleteTreeNodes(root->right);
	delete root;
	root = NULL;
}

// Performs the splay operation
void BST::splay(stack<BSTNode*>& S) {
	while (S.size() > 1) {
		BSTNode* x = S.top(); S.pop();
		BSTNode* p = S.top(); S.pop();
		BSTNode* g = NULL;
		if (!S.empty()) { g = S.top(); S.pop(); }
		BSTNode* pg = NULL; // Parent of gp
		if (!S.empty()) pg = S.top();

		// Classify & Perform rotation
		if (g == NULL) {
			if (x == p->left) {
				// Zig
				p->left = x->right;
				x->right = p;
			}
			else {
				// x == p->right
				// Zag
				p->right = x->left;
				x->left = p;
			}

			root = x;
			break;
		}
		else {
			// 4 cases -- Req double rotation
			if (p == g->left) {
				if (x == p->left) {
					// Zig - Zig
					g->left = p->right;
					p->right = g;
					p->left = x->right;
					x->right = p;
				}
				else {
					// Zig - Zag
					g->left = x->right;
					x->right = g;
					p->right = x->left;
					x->left = p;
				}
			}
			else {
				if (x == p->right) {
					// Zag - Zag
					g->right = p->left;
					p->left = g;
					p->right = x->left;
					x->left = p;
				}
				else {
					// Zag - Zig
					g->right = x->left;
					x->left = g;
					p->left = x->right;
					x->right = p;
				}
			}

			if (pg == NULL) { root = x; break; }
			else if (g == pg->left) pg->left = x;
			else pg->right = x;

			S.push(x);

		}
	}
}

// Checks if the given key exists in the tree
bool BST::find(int key) {
	stack<BSTNode*> S;
	BSTNode* p = root;

	while (p) {
		S.push(p);
		if (key == p->key) { 
			// Splay the node to the root by rotations
			splay(S);
			return true; 
		}
		if (key < p->key) p = p->left;
		else			  p = p->right;
	}
	return false;
}

// Returns minimum key in the BST
int BST::min() {
	if (root == NULL) throw std::exception("BST::min - Tree is empty");

	BSTNode* p = root;
	while (p->left != NULL) p = p->left;

	return p->key;
}

// Returns maximum key in the BST
int BST::max() {
	if (root == NULL) throw std::exception("BST::max - Tree is empty");

	BSTNode* p = root;
	while (p->right != NULL) p = p->right;

	return p->key;
}

// Adds new item to the tree
void BST::add(int key) {
	BSTNode* q = NULL;
	BSTNode* p = root;
	while (p) {
		q = p;
		if (p->key == key) { return; }
		else if (key < p->key) { p = p->left; }
		else { p = p->right; }
	}

	BSTNode* node = new BSTNode(key);
	if (root == NULL) root = node;
	else if (key < q->key) q->left = node;
	else q->right = node;
}

// Removes a given key from the BST
void BST::remove(int key) {
	BSTNode* pp = NULL;
	BSTNode* p = root;

	while (p && p->key != key) {
		pp = p;
		if (key < p->key) p = p->left;
		else			  p = p->right;
	}

	// Key does not exist
	if (p == NULL) return;

	// Node has 2 children
	if (p->left && p->right) {
		BSTNode* qp = p;
		BSTNode* q = p->left;

		while (q->right) {
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
}

// In-Order Traversal
void BST::printAux(BSTNode* root) {
	if (root == NULL) return;
	printAux(root->left);
	printf("%d, ", root->key);
	printAux(root->right);
}

void BST::print() {
	std::cout << "BST Keys: ";
	printAux(root);
	std::cout << std::endl;
}

void BST::LevelValues(BSTNode* root) {
	if (root == NULL) return;

	// <node, level>
	queue<pair<BSTNode*, int>> Q;
	int currentLevel = 0;
	Q.push(make_pair(root, currentLevel));

	printf("Level[%d]: ", currentLevel);

	while (!Q.empty()) {
		BSTNode* p = Q.front().first;
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

void BST::printLevelByLevel() {
	LevelValues(root);
	std::cout << std::endl;

}