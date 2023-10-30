/*Rachel Berlin 212316400
Michal Seror 212329221
Ex3*/
#include<string>
#include <iostream>
using namespace std;
#pragma once
class Trie
{
protected:
	class TrieNode {
	public:
		TrieNode* children[30] = { 0 };//max children
		TrieNode* father;
		bool isEndWord = false;
		char tav = 0;
		TrieNode() {};
	};
	TrieNode* root;
public:
	Trie() { root = new TrieNode; }
	void insertWord(string str) { insertWord(str, root); }//to insert a word
	bool deleteWord(string str) { return deleteWord(str, root); }//to delete a word
	bool searchWord(string str) { return searchWord(str, root); }//to search a word
	bool printAutoSuggestions(string str) { return printAutoSuggestions(str, root); }//to print all the words
	
private:
	bool searchWord(string str, TrieNode* node);//search if the word exist in the tree
	void insertWord(string str, TrieNode* p);//insert the word into the tree
	bool deleteWord(string str, TrieNode* p);//delete the word from the tree
	bool printAutoSuggestions(string str, TrieNode* p); //print all the words that continue this str
	void printTree(string str, TrieNode* P);//print all the words in the tree p as they start with str 
	bool checkIfSons(TrieNode* p );//check if p have a words in it
	TrieNode* searchPofWord(string str, TrieNode* p) {//find the word in the tree and return pointer to the latest char
		int index = str[0] - 97;
		if (str.length() == 1)
		{
			if (p->children[index]->isEndWord == true) return p->children[index];
			else return NULL;
		}
		if (p->children[index]->tav == 0) return NULL;
		else
		{
			string str1;
			for (int i = 1; i < str.length(); i++) str1 += str[i];
			return searchPofWord(str1, p->children[index]);
		}
	}
};

