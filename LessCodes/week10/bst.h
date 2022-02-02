#pragma once

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

public:
	BST() { root = NULL; }
	~BST() { deleteTreeNodes(root); }
	bool find(int key);
	int min();
	int max();
	void add(int key);
	void remove(int key);
	void print();
};

// Delete all nodes in the tree
void BST::deleteTreeNodes(BSTNode* node) {
	if (node == NULL) return;
	deleteTreeNodes(root->left);
	deleteTreeNodes(root->right);
	delete root;
	root = NULL;
}


// Checks if the given key exists in the tree
bool BST::find(int key) {
	BSTNode* p = root;

	while (p) {
		if (key == p->key) return true;
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

