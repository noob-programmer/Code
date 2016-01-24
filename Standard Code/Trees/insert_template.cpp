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
	stack<BST *> stck;	
	void insert_BST(int data);
	BST * insert_BST_recursive(BST *,int);
	void inorder(BST *);
	void inorder_iterative(BST *);

};

void BST::insert_BST(int x)
{
	BST *node=(BST*)new int(sizeof(int));
	node->data=x;
	BST *parent;
	BST *current;
	if(root==NULL)
	{
		root=node;
		return;
	}
	parent=NULL,current=root;
	while(current!=NULL)
	{
		parent=current;
		if(current->data > x)
		{
			current=current->left;
		}
		else
		{
			current=current->right;
		}
	}
	if(parent->data >x)
	{
		parent->left=node;
	}
	else
	{
		parent->right=node;
	}
	return;
}
BST * BST::insert_BST_recursive(BST *temp,int x)
{
	BST *node=(BST *)new int (sizeof(int));
	node->data=x;
	if(temp == NULL)
	{
		temp=node;
	}
	else
	{
		if(temp->data > x)
		{
			temp->left=insert_BST_recursive(temp->left,x);
		}
		else if(temp->data < x)
		{
			temp->right=insert_BST_recursive(temp->right,x);
		}
	}
	return temp;
}
void  BST::inorder_iterative(BST *temp)
{
	if(temp==NULL)
		return;
	while(true)
	{
		if(temp!=NULL)
		{
			stck.push(temp);
			temp=temp->left;
		}
		else
		{
			if(stck.empty())
			{
				break;
			}
			BST *x=stck.top();
			cout<<x->data<<"\t";
			stck.pop();
			temp=temp->right;
		}
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
	int size,i,input,num;
	cout<<"enter size"<<endl;
	cin>>size;
	cout<<"enter elements"<<endl;
	for(i=0;i<size;i++)
	{
		cin>>input;
		obj.root=obj.insert_BST_recursive(obj.root,input);	
	}
	obj.inorder_iterative(obj.root);
	cout<<endl;
	return 0;
}