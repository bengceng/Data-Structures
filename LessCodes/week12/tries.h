#pragma once
#include <string>

#define NO_LETTERS 26

struct TrieNode {
	TrieNode* children[NO_LETTERS];
	bool storesValue;

	TrieNode() {
		for (int i = 0; i < NO_LETTERS; i++) children[i] = NULL;
		storesValue = false;
	}
};

class Trie {
private:
	TrieNode *root[NO_LETTERS];

	void deleteNodes(TrieNode* ptr);

public:

	Trie() {for (int i = 0; i < NO_LETTERS; i++) root[i] = NULL;}
	~Trie() {for (int i = 0; i < NO_LETTERS; i++) deleteNodes(root[i]);}
	void insert(string word);
	bool search(string word);
	bool startsWith(string prefix);
};

void Trie::deleteNodes(TrieNode* ptr) {
	if (ptr == NULL) return;
	for (int i = 0; i < NO_LETTERS; i++) deleteNodes(ptr->children[i]);
	delete ptr;
}

// Insert a word into the trie
void Trie::insert(string word) {
	for (uint32_t i = 0; i < word.length(); i++) word[i] -= 'a';

	if (root[word[0]] == NULL) root[word[0]] = new TrieNode();

	TrieNode* p = root[word[0]];

	for (uint32_t i = 1; i < word.length(); i++) {
		if (p->children[word[i]] == NULL) p->children[word[i]] = new TrieNode();
		p = p->children[word[i]];
	}
	p->storesValue = true;
}

// Search the given word in the tree
bool Trie::search(string word) {
	for (uint32_t i = 0; i < word.length(); i++) word[i] -= 'a';

	TrieNode* p = root[word[0]];
	for (uint32_t i = 1; p && i < word.length(); i++) {
		p = p->children[word[i]];
	}
	return p && p->storesValue;
}

// Search if any word in the trie starts with given prefix
bool Trie::startsWith(string prefix) {
	for (uint32_t i = 0; i < prefix.length(); i++) prefix[i] -= 'a';

	TrieNode* p = root[prefix[0]];
	for (uint32_t i = 1; p && i < prefix.length(); i++) {
		p = p->children[prefix[i]];
	}

	return p != NULL;
}