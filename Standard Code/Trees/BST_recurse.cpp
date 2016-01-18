#include <bits/stdc++.h>
using namespace std;
class BST
{
public:
	int data;
	BST *left=NULL;
	BST *right=NULL;
	BST *root=NULL;
	BST *node;
	BST *parent=NULL;
	void insert_BST(BST *,int data);
	void inorder(BST *);
};
void BST::insert_BST(BST *root1,int x)
{
	BST *node=(BST*)new int (sizeof(int));
	node->data=x;
	//BST *parent;
	if(root==NULL)
	{
		root=node;
		root1=root;
		return;
	}
	if(root1==NULL)
	{
		if(parent->data > x)
		{
			parent->left=node;
			return;
		}
		else
		{
			parent->right=node;
			return;	
		}
	}
	parent=root1;
	if(root1->data > x)
	{
		
		insert_BST(root1->left,x);
	}
	else
	{
		
		insert_BST(root1->right,x);
	}
}


void BST::inorder(BST *root)
{
	if(root==NULL)
		return;
	BST *temp=root;
	inorder(temp->left);
	cout<<temp->data<<"\t";
	inorder(temp->right);
}
int main()
{
	BST obj;
	int size,i,input;
	cin>>size;
	for(i=0;i<size;i++)
	{
		cin>>input;
		obj.insert_BST(obj.root,input);	
	}
	obj.inorder(obj.root);
	return 0;
}