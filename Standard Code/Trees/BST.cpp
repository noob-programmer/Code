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
	void inorder(BST *);
	BST* search(BST *,int data);
	bool is_BST(BST *,int min,int max);
	int height(BST *);
	int find_min(BST *);

	void BST_delete(BST *temp_root,int data);
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
void BST::inorder(BST *root)
{
	if(root==NULL)
		return;
	BST *temp=root;
	inorder(temp->left);
	cout<<temp->data<<"\t";
	inorder(temp->right);
}
BST* BST::search(BST *root1,int data)
{
	if(root1==NULL)
	{
		return NULL;
	}
	if(root1->data==data)
	{
		return root1;
	}
	else if(root1->data > data)
	{
		search(root1->left,data);
	}
	else
	{
		search(root1->right,data);
	}

}
bool BST::is_BST(BST *root1,int min,int max)
{
	if(root1==NULL)
		return true;
	if(root1->data <=min || root1->data >max)
	{
		return false;
	}
	return ( is_BST(root1->left,min,root1->data) &&
	is_BST(root1->right,root1->data,max) );
}
int BST::height(BST *root1)
{
	if(root1==NULL)
		return 0;
	int left=height(root1->left);
	int right=height(root1->right);
	return 1+max(left,right);
}
int BST::find_min(BST *temp)
{
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp->data;
}
void BST::BST_delete(BST *temp_root,int data)
{
		BST *temp1;
		
		if(temp_root==NULL)
		{
			return ;
		}
		if(data <temp_root->data)
		{
			BST_delete(temp_root->left,data);
		}
		else if(temp_root->data<data)
		{
			BST_delete(temp_root->right,data);
		}
		else if(temp_root->left!=NULL && temp_root->right!=NULL)
		{
			temp_root->data=find_min(temp_root->right);
			BST_delete(temp_root->right,temp_root->data);
			
		}
		else 
		{
			BST *oldnode=temp_root;
			temp_root=(temp_root->left!=NULL)?temp_root->left:temp_root->right;
			delete oldnode;
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
	obj.inorder(obj.root);
	cout<<endl;
	cout<<"enter number to find"<<endl;
	cin>>num;
	BST *temp1;
	if(temp1=obj.search(obj.root,num))
	{
		cout<<"Found!"<<endl;
	}
	else
	{
		cout<<"Not Found :("<<endl;
	}
	cout<<"BST or Not?"<<endl;
	if(obj.is_BST(obj.root,INT_MIN,INT_MAX))
	{
		cout<<"BST!"<<endl;
	}
	else
	{
		cout<<"Not a BST :("<<endl;
	}
	cout<<"Height is ";
	cout<<obj.height(obj.root)<<endl;
	cout<<"the tree is..."<<endl;
	obj.inorder(obj.root);
	cout<<endl;
	cout<<"enter number to be deleted"<<endl;
	cin>>num;
	cout<<endl;
	obj.BST_delete(obj.root,num);
	
		
		obj.inorder(obj.root);
		cout<<endl;
	
	
	return 0;
}