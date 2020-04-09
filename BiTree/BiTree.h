#ifndef BITREE_H
#define BITREE_H

#include <iostream>

using namespace std;

typedef int ItemType;

struct TreeNode
{
	ItemType info;
	TreeNode* left;
	TreeNode* right;
};

enum LeftOrRight
{
	Greater, Less, Equal
};

class BiTree
{
public:
	BiTree();
	~BiTree();

	BiTree(BiTree& oTree);
	void operator=(BiTree& oTree);
	void MakeEmpty();
	bool IsEmpty();
	bool IsFull();
	int GetLength();
	ItemType GetItem(ItemType item, bool& found);
	void PutItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetTree();
	ItemType GetNextItem(bool& finished);
	void Print(ofstream &outfile);

	void BPutItem(ItemType item);

private:
	TreeNode* root;

	LeftOrRight Evaluation(ItemType item, ItemType compare);

	void BInsert(TreeNode* node, ItemType item);
	void Delete(TreeNode* node, ItemType item);
	void DeleteNode(TreeNode* node);
};

#endif // !BITREE_H

