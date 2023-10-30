/*Rachel Berlin 212316400
Michal Seror 212329221
Ex3*/
#include "Trie.h"

void Trie::insertWord(string str, TrieNode* root)//to insert a word
{
	TrieNode* p = root;
		for (int i = 0; i < str.size(); i++)//to reset the word
		{
			int index = str[i] - 97;
			if (p->children[index] == NULL) {
				p->children[index] = new TrieNode;
				p->children[index]->tav = str[i];
				p->children[index]->father = p;
			}
			p = p->children[index];
		}
		p->isEndWord = true;//end word ==true
	}

bool Trie::deleteWord(string str, TrieNode* p)//to delete a word
{
	if (!p)//if the trie 
	{
		return false;
	}
	if (searchWord(str, p) == false)//if the word not found
		return false;
	p = searchPofWord(str, p);
	p->isEndWord = false;
	bool noChild = true;
	for (int i = 0; i < 30; i++)
		if (p->children[i] != NULL)
			noChild = false;
	if (noChild)
		p->tav = 0;
	return true;
}

bool Trie::searchWord(string str, TrieNode* p )//to search a word
{
	int index = str[0] - 97;//the index's str
	if (str.length() == 1) 
	{
		if (p->children[index] != NULL && p->children[index]->isEndWord == true) return true;//if the str found
		else return false;
	}
	else {
		if (p->children[index] == NULL) return false;
		else
		{
			string str1;
			for (int i = 1; i < str.length(); i++) str1 += str[i];
			return searchWord(str1, p->children[index]);
		}
	}
}
bool Trie::printAutoSuggestions(string str, TrieNode* p)//to print all the words
{
	if (!p) return false;
	for (int i = 0; i < str.length(); i++) {//to run on all
		int index = str[i] - 97;
		if (p->children[index])
			p = p->children[index];
		else return false;
	}
	if (!checkIfSons(p))//if not have childs
		return false;
	printTree(str, p);
	return true;
}

void Trie::printTree(string str, TrieNode* p)//the print the trie
{
	if (p->isEndWord) {
		cout << str << "\n";
	}
	for (int i = 0; i < 30; i++) 
		if (p->children[i] != NULL)
			printTree(str + p->children[i]->tav, p->children[i]);
}

bool Trie::checkIfSons(TrieNode* p)//cheak if the trie have sons
{
	if(p->isEndWord) {
		return true;
	}
	for (int i = 0; i < 30; i++)
		if (p->children[i] != NULL)
			return checkIfSons(p->children[i]);
	return false;
}




