#include <iostream>
using namespace std;
struct Node 
{
	int key;
	int balance;
	Node* pLeft;
	Node* pRight;
};
Node* taoNode(int value)
{
	Node* p = new Node;
	p->key = value;
	p->balance = 0;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
void xoaCay(Node* root)
{
	if (root != NULL)
	{
		xoaCay(root->pLeft);
		xoaCay(root->pRight);
		delete root;
	}
}
void insert(Node* &root,int value)
{
	if (root == NULL)
		root = taoNode(value);
	else if (value > root->key)
		insert(root->pRight, value);
	else if (value < root->key)
		insert(root->pLeft, value);
}
void xuatLNR(Node* root)
{
	if (root != NULL)
	{
		xuatLNR(root->pLeft);
		cout << root->key << " ";
		xuatLNR(root->pRight);
	}
}
void xuatNLR(Node* root)
{
	if (root != NULL)
	{
		cout << root->key << " ";
		xuatNLR(root->pLeft);
		xuatNLR(root->pRight);
	}
}
void xoayTrai(Node* &root)
{
	Node* temp = root->pRight;
	root->pRight = temp->pLeft;
	temp->pLeft = root;
	root = temp;
}
void xoayPhai(Node* &root)
{
	Node* temp = root->pLeft;
	root->pLeft = temp->pRight;
	temp->pRight = root;
	root = temp;
}
void main()
{
	Node* AVLTree = NULL;
	insert(AVLTree, 10);
	insert(AVLTree, 8);
	insert(AVLTree, 7);
	insert(AVLTree, 9);
	insert(AVLTree, 12);
	insert(AVLTree, 11);
	insert(AVLTree, 13);
	xuatNLR(AVLTree);
	cout << endl;
	xoayPhai(AVLTree);
	xuatNLR(AVLTree);
	cout << endl;
	xoaCay(AVLTree);
}