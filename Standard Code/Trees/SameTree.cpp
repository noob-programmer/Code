#include <bits/stdc++.h>
using namespace std;
class BST
{
public:
	int data;
	BST *left=NULL;
	BST *right=NULL;
	BST *root=NULL;
	BST *root1=NULL;
	BST *node;
	//stack<BST *> stck;	
	void insert_BST(int data);
	BST * insert_BST_recursive(BST *,int);
	void inorder(BST *);
	void SameTree(BST *temp1,BST *temp2);
	//void inorder_iterative(BST *);

};
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
void BST::inorder(BST *root)
{
	if(root==NULL)
		return;
	BST *temp=root;
	inorder(temp->left);
	cout<<temp->data<<"\t";
	inorder(temp->right);
}
void BST::SameTree(BST *temp1,BST *temp2)
{
		int flag=1;
		if(temp1==NULL && temp2==NULL)
			return;
		SameTree(temp1->left,temp2->left);
		if(temp1->data!=temp2->data)
		{
			flag=0;
			cout<<"Not Same!"<<endl;
			exit(0);
			//return;
		}
		SameTree(temp1->right,temp2->right);
		if(flag)
		{
			cout<<"Same!"<<endl;
			exit(0);
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
		obj.root=obj.insert_BST_recursive(obj.root,input);	
	}
	obj.inorder(obj.root);
	cout<<endl;

	cout<<"enter size"<<endl;
	cin>>size;
	cout<<"enter elements"<<endl;
	for(i=0;i<size;i++)
	{
		cin>>input;
		obj.root1=obj.insert_BST_recursive(obj.root1,input);	
	}
	obj.inorder(obj.root);
	cout<<endl;
	obj.SameTree(obj.root,obj.root1);
	cout<<endl;
	return 0;
}