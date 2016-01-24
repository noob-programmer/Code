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
	void insert_BST(int data);
	//void inorder(BST *);
	//BST* search(BST *,int data);
	//bool is_BST(BST *,int min,int max);
	//int height(BST *);
	//int find_min(BST *);
//	stack<int>stck;
	//BST* BST_delete(BST *temp_root,int data);
	//void inorder_iterative(BST *);
	queue<BST *>q;
	void level_order(BST *);

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
void BST::level_order(BST *root)
{
	q.push(root);
	while(!q.empty())
	{
		cout<<(q.front()->data)<<"\t";
		root=q.front();
		q.pop();
		if(root->left)
		{
			q.push(root->left);
		}
		if(root->right)
		{
			q.push(root->right);	
		}
	}
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
		obj.insert_BST(input);	
	}
	obj.level_order(obj.root);
	return 0;
}