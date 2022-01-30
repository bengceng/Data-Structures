#include "ThreadedBST.h"
#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;

///-----------------------------------------------
/// Erases all nodes in the tree
/// 

BSTNode*  inSucc(BSTNode*  ptr)
{
	if (ptr->rightLinkType == CHILD)
		return ptr->right;

ptr = ptr->right;
while (ptr->leftLinkType == THREAD)
ptr = ptr->left;

return ptr;
}

BSTNode*  inPred(BSTNode*  ptr)
{
	if (ptr->leftLinkType == CHILD)
		return ptr->left;

	ptr = ptr->left;
	while (ptr->rightLinkType == THREAD)
		ptr = ptr->right;
	return ptr;
}
void caseA(BSTNode* par, BSTNode* ptr)
{

	// If Node to be deleted is left
	// of its parent
	if (ptr == par->left) {
		par->leftLinkType = CHILD;
		par->left = ptr->left;
	}
	else {
		par->rightLinkType = CHILD;
		par->right = ptr->right;
	}

	// Free memory and return new root
	delete ptr;

}

// Here 'par' is pointer to parent Node and 'ptr' is
// pointer to current Node.
void caseB(BSTNode* par, BSTNode* ptr)
{
	BSTNode* child;

	// Initialize child Node to be deleted has
	// left child.
	if (ptr->leftLinkType == THREAD)
		child = ptr->left;

	// Node to be deleted has right child.
	else
		child = ptr->right;



	// Node is left child of its parent.
	if (ptr == par->left)
		par->left = child;
	else
		par->right = child;

	// Find successor and predecessor
	BSTNode* s = inSucc(ptr);
	BSTNode* p = inPred(ptr);

	// If ptr has left subtree.
	if (ptr->leftLinkType == THREAD)
		p->right = s;

	// If ptr has right subtree.
	else {
		if (ptr->rightLinkType == THREAD)
			s->left = p;
	}

	delete ptr;

}

// Here 'par' is pointer to parent Node and 'ptr' is
// pointer to current Node.
void caseC(BSTNode*par, BSTNode* ptr)
{
	// Find inorder successor and its parent.
	BSTNode* parsucc = ptr;
	BSTNode*succ = ptr->right;

	// Find leftmost child of successor
	while (succ->leftLinkType == THREAD) {
		parsucc = succ;
		succ = succ->left;
	}

	ptr->key = succ->key;

	if (succ->leftLinkType == CHILD && succ->rightLinkType == CHILD)
		caseA(parsucc, succ);
	else
		caseB(parsucc, succ);


}
void ThreadedBST::eraseTreeNodes(BSTNode* node) {
	//if (node == NULL) return;
	   //eraseTreeNodes(node->left);
	   //eraseTreeNodes(node->right);
	   //delete node;
	if (root == NULL)
		return;
	BSTNode* ptr = root;
	BSTNode* temp = NULL;
	while (ptr->leftLinkType == THREAD)
		ptr = ptr->left;
	while (ptr != NULL) {
		temp = next(ptr);
		delete ptr;
		ptr = temp;
	}
	delete ptr;
	delete temp;
} //end-eraseTreeNodes

///-----------------------------------------------
/// Adds a given key to the BST
/// 
void ThreadedBST::add(int key) {
	// Fill this in
	BSTNode* current = this->getRoot();
	BSTNode* parent = NULL;

	while (current != NULL)
	{
		if (key == current->key) return;
		parent = current;
		if (key < current->key)
		{
			if (current->leftLinkType == THREAD)
				current = current->left;
			else // eger lefLinkType == CHILD ise burda bir çocuga sahip yani left kýsmýnda bir node var 
				break;
		}
		else // key > current->key
		{
			if (current->rightLinkType == THREAD) {
				current = current->right;
			}
			else {
				break;
			}
		}
	}

	BSTNode *node_to_add = new BSTNode(key);
	node_to_add->leftLinkType = CHILD;
	node_to_add->rightLinkType = CHILD;
	if (parent == NULL) //kök yoksa
	{
		this->root = node_to_add;
	}
	else if (key < parent->key) {//burda parent ýn bir önceki degeriyle parent arasýna yeni deðeri (node_to_add)ekliyoruz
		node_to_add->left = parent->left;
		node_to_add->right = parent;
		parent->left = node_to_add;
		parent->leftLinkType = THREAD;

	}
	else // key>parent->key
	{   //burda parent ýn bir sonraki degeriyle parent arasýna yeni deðeri (node_to_add)ekliyoruz
		node_to_add->left = parent;
		node_to_add->right = parent->right;
		parent->right = node_to_add;
		parent->rightLinkType = THREAD;
	}
} // end-add

///-----------------------------------------------
/// Removes a given key from the BST (if it exists)
/// 
void ThreadedBST::remove(int key) {
	// Fill this in



	BSTNode* current = this->getRoot();
	BSTNode* parent = NULL;

	while (current != NULL) {

		if (key == current->key)
			break;
		parent = current;
		if (key < current->key) {
			if (current->leftLinkType == THREAD)
				current = current->left;
			else
				break;
		}

		else {
			if (key > current->key) {
				if (current->rightLinkType == THREAD)
					current = current->right;
				else
					break;
			}
		}
	}

	////LEAF
	//if (current->rightLinkType == THREAD && current->leftLinkType == THREAD) {
	//	if (current->key < parent->key) //soldan silicem
	//	{
	//		parent->left = current->left;
	//		parent->leftLinkType = THREAD;
	//		delete current;
	//	}
	//	else {

	//		parent->right = current->right;
	//		parent->rightLinkType = THREAD;
	//		delete current;
	//	}
	//}

	// Two Children
	if (current->leftLinkType == THREAD && current->rightLinkType == THREAD)
		caseC(parent, current);

	// Only Left Child
	else if (current->leftLinkType == THREAD)
		caseB(parent, current);

	// Only Right Child
	else if (current->rightLinkType == THREAD)
		caseB(parent, current);

	// No child
	else
		caseA(parent, current);



	////tek cocuk varsa
	//BSTNode* child;
	//// Initialize child Node to be deleted has
	//// left child.
	//if (current->leftLinkType == CHILD && current->rightLinkType==THREAD)
	//	child = current->left;

	//// Node to be deleted has right child.
	//else
	//	child = current->right;
	//// Node to be deleted is root Node.
	//if (parent == NULL)
	//		this->root = child;

	//// Node is left child of its parent.
	//else if (current == parent->left)
	//		parent->left = child;
	//else
	//		parent->right = child;
	//// Find successor and predecessor
	//BSTNode* s = inSucc(current);
	//BSTNode* p = inPred(current);
	//// If CURR has left subtree.
	//if (current->leftLinkType == CHILD)
	//	p->right = s;

	//// If ptr has right subtree.
	//else {
	//	if (current->rightLinkType == CHILD)
	//		s->left = p;
	//}




	////iki cocuk
	//// Find inorder successor and its parent.
	//BSTNode*  parsucc = current;
	//BSTNode*  succ = current->right;

	//// Find leftmost child of successor
	//while (succ->left != NULL) {
	//	parsucc = succ;
	//	succ = succ->left;
	//}

	//current->key = succ->key;

	//if (succ->leftLinkType == THREAD && succ->rightLinkType == THREAD) {
	//	if (succ->rightLinkType == THREAD && succ->leftLinkType == THREAD) {
	//		if (succ->key < parsucc->key) //soldan silicem
	//		{
	//			parsucc->left = succ->left;
	//			parsucc->leftLinkType = THREAD;
	//			delete succ;
	//		}
	//		else {

	//			parsucc->right = succ->right;
	//			parsucc->rightLinkType = THREAD;
	//			delete succ;
	//		}
	//	}
	//}
	//	
	//else
	//{
	//	BSTNode* child_;
	//	// Initialize child Node to be deleted has
	//	// left child.
	//	if (succ->leftLinkType == CHILD)
	//		child_ = succ->left;

	//	// Node to be deleted has right child.
	//	else
	//		child_ = succ->right;
	//	// Node to be deleted is root Node.
	//	if (parsucc == NULL)
	//		this->root = child_;

	//	// Node is left child of its parent.
	//	else if (succ == parsucc->left)
	//		parsucc->left = child_;
	//	else
	//		parsucc->right = child_;
	//	// Find successor and predecessor
	//	BSTNode* ss = inSucc(succ);
	//	BSTNode* pp = inPred(succ);
	//	// If CURR has left subtree.
	//	if (succ->leftLinkType == CHILD)
	//		pp->right = ss;

	//	// If ptr has right subtree.
	//	else {
	//		if (succ->rightLinkType == CHILD)
	//			ss->left = pp;
	//	}
	//}
	//delete current;
}

//void ThreadedBST::inorderTraverse()
//{
//	BSTNode* root = this->root;
//	if (root == NULL)
//		cout << "Tree is empty" << endl;
//	BSTNode* ptr = root;
//	while (ptr->leftLinkType == THREAD)
//		ptr = ptr->left;
//	while (ptr != NULL) {
//		cout << ptr->key << " ";
//		ptr = next(ptr);
//	}
//}

///-----------------------------------------------
/// Searches a given key in the ThreadedBST
/// Return a pointer to the node that holds the key
/// If the key is not found, return NULL
/// 
BSTNode *ThreadedBST::find(int key) {
	// Fill this in
	BSTNode* target = this->getRoot();
	while (target != NULL)
	{
		if (target->key == key)
		{
			return target;
		}
		else if (target->key > key)
		{
			target = target->left;
		}
		else {
			target = target->right;
		}
	}
	// key is not exist....
	return NULL;
} // end-find

///-----------------------------------------------
/// Returns the minimum key in the ThreadedBST
/// Return a pointer to the node that holds the key
/// If the key is not found, return NULL
/// 
BSTNode* ThreadedBST::min() {
	BSTNode *node = this->root;
	while (node->left != NULL) {
		node = node->left;
	}
	return node;
} // end-min

///-----------------------------------------------
/// Returns the maximum key in the ThreadedBST
/// Return a pointer to the node that holds the key
/// If the key is not found, return NULL
/// 
BSTNode* ThreadedBST::max() {
	// Fill this in

	BSTNode* node = this->root;
	while (node->right != NULL) {
		node = node->right;
	}
	return node;

} // end-max

///-----------------------------------------------
/// Given a valid pointer to a node in ThreadedBST,
/// returns a pointer to the node that contains the inorder predecessor
/// If the inorder predecessor does not exist, returns NULL
/// 
BSTNode* ThreadedBST::previous(BSTNode* ptr) {
	if (ptr->leftLinkType == CHILD)
		return ptr->left;
	ptr = ptr->left;
	while (ptr->rightLinkType == THREAD)
		ptr = ptr->right;
	return ptr;
} // end-previous

///-----------------------------------------------
/// Given a valid pointer to a node in the ThreadedBST,
/// returns a pointer to the node that contains the inorder successor
/// If the inorder successor does not exist, returns NULL
/// 
BSTNode* ThreadedBST::next(BSTNode* ptr) {

	if (ptr->rightLinkType == CHILD)
		return ptr->right;
	ptr = ptr->right;
	while (ptr->leftLinkType == THREAD)
		ptr = ptr->left;
	return ptr;
} // end-next