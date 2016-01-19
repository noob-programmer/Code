#include <bits/stdc++.h>
using namespace std;
class List
{
public:
	List *start=NULL;
	List *link=NULL;
	int data;
	void List_insert_rear(int);
	void display(List *);
	void List_insert_front(int key);
	void List_delete_front(List *);
	void List_delete_rear(List *);
	void List_reverse(List *);
	void List_reverse_recursive(List *);
	void List_print_reverse(List *);
};
void List::List_insert_rear(int key)
{
	List *temp=(List *)new int (sizeof(int));
	List *temp1=start;
	temp->data=key;
	if(start==NULL)
	{
		start=temp;
		return;
	}
	while(temp1->link!=NULL)
	{
		temp1=temp1->link;
	}
	temp1->link=temp;
	return;
}
void List::List_insert_front(int key)
{
	List *temp=(List *)new int (sizeof(int));
	temp->data=key;
	if(start==NULL)
	{
		start=temp;
		return;		
	}
	temp->link=start;
	start=temp;
	return;
}
void List::display(List *temp)
{
	if(temp==NULL)
	{
		cout<<"Empty List"<<endl;
	}
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->link;
	}
	return;
}
void List::List_delete_front(List *temp)
{
	if(temp==NULL)
	{
		cout<<"Empty List"<<endl;
		return;
	}
	start=temp->link;
	delete(temp);
}
void List::List_delete_rear(List *temp)
{
	List *prev=NULL;
	if(temp==NULL)
	{
		cout<<"Empty List"<<endl;
		return;
	}
	while(temp->link!=NULL)
	{
		prev=temp;
		temp=temp->link;
	}
	prev->link=NULL;
	delete(temp);
}
void List::List_reverse(List *temp)
{
	List *current=temp,*prev=NULL,*next=NULL;
	if(temp==NULL)
	{
		cout<<"Empty List"<<endl;
		return;
	}
	while(current!=NULL)
	{
		next=current->link;
		current->link=prev;
		prev=current;
		current=next;
		
	}
	start=prev;
	return;
}
void List::List_reverse_recursive(List *temp)
{
	if(temp->link==NULL)
	{
		start=temp;
		return;
	}
	List_reverse_recursive(temp->link);
	List *q=temp->link;
	q->link=temp;
	temp->link=NULL;
}
void List::List_print_reverse(List *temp)
{
	if(temp==NULL)
	{
		return;
	}
	List_print_reverse(temp->link);
	cout<<temp->data<<"\t";
	
}
int main()
{
	List obj;
	int key,size,i;
	cout<<"enter the size of list to insert"<<endl;
	cin>>size;
	for(i=0;i<size;i++)
	{
		cin>>key;
		obj.List_insert_front(key);
	}
	obj.display(obj.start);
	cout<<endl;
	cout<<"delete front"<<endl;
	obj.List_delete_front(obj.start);
	obj.display(obj.start);
	cout<<endl;
	cout<<"Delete Rear"<<endl;
	obj.List_delete_rear(obj.start);
	obj.display(obj.start);
	cout<<endl;
	cout<<"Reverse"<<endl;
	obj.List_reverse(obj.start);
	obj.display(obj.start);
	cout<<endl;
	cout<<"Reverse recursive"<<endl;
	obj.List_reverse_recursive(obj.start);
	obj.display(obj.start);
	cout<<endl;
	cout<<"Reverse Print"<<endl;
	obj.List_print_reverse(obj.start);
	cout<<endl;
	return 0;
}
