#include "BiTree.h"
#include <iostream>

using namespace std;

BiTree::BiTree()
{
	root = nullptr;
}

BiTree::~BiTree()
{
	MakeEmpty();
}

BiTree::BiTree(BiTree& oTree)
{
}

void BiTree::operator=(BiTree& oTree)
{
}

void BiTree::MakeEmpty()
{

}

bool BiTree::IsEmpty()
{
	if (root == nullptr)
		return true;

	return false;
}

bool BiTree::IsFull()
{
	try
	{
		TreeNode* temp = new TreeNode;

		delete temp;
		return false;
	}
	catch(bad_alloc e)
	{
		return true;
	}
}

int BiTree::GetLength()
{
	return 0;
}

ItemType BiTree::GetItem(ItemType item, bool& found)
{
	return ItemType();
}

void BiTree::PutItem(ItemType item)
{
	if (root == nullptr)
	{
		root = new TreeNode;
		root->info = item;
		root->left = nullptr;
		root->right = nullptr;
	}
	else if (!IsFull())
	{
		TreeNode* pos = root;

		do
		{
			switch (Evaluation(pos->info, item))
			{
			case Less: if (pos->left == nullptr)
			{
				pos->left = new TreeNode;
				pos->left->info = item;
				pos = pos->left;
				pos->left = nullptr;
				pos->right = nullptr;
			}
					 else
			{
				pos = pos->left;
			}
					 break;
			case Greater: if (pos->right == nullptr)
			{
				pos->right = new TreeNode;
				pos->right->info = item;
				pos = pos->right;
				pos->left = nullptr;
				pos->right = nullptr;
			}
						else
			{
				pos = pos->right;
			}
				break;
			default:
				cout << "Item is on the list or there was an error!\n";
				break;
			}
		} while (pos->info != item);
	}
}

void BiTree::DeleteItem(ItemType item)
{
}

void BiTree::ResetTree()
{
}

ItemType BiTree::GetNextItem(bool& finished)
{
	return ItemType();
}

void BiTree::Print(ofstream outfile)
{
}

LeftOrRight BiTree::Evaluation(ItemType item, ItemType compare)
{
	if (compare < item)
		return Less;
	else if (compare > item)
		return Greater;

	return Equal;
}
