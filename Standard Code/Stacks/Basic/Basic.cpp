#include <bits/stdc++.h>
using namespace std;
#define SIZE 10
int top=-1;
int arr[SIZE];
void push(int key)
{
	if(top>SIZE-1)
	{
		cout<<"Stack overflow"<<endl;
		return;
	}
	arr[++top]=key;
}
int pop()
{
	if(top==-1)
	{
		cout<<"stack Underflow"<<endl;
		return INT_MIN;
	}
	return arr[top--];
}
int stck_top()
{
	if(top== -1)
	{
		cout<<"Error"<<endl;
		return INT_MIN;
	}
	return arr[top];
}
bool is_empty()
{
	if(top==-1)
		return true;
	else
		return false;
}
int main()
{
	int size,i;
	cout<<"enter the array size"<<endl;
	cin>>size;
	cout<<"enter elements to push"<<endl;
	for(i=0;i<size;i++)
	{
		push(i);
	}
	for(i=0;i<size;i++)
		cout<<arr[i]<<"\t";
	cout<<endl;
	cout<<"Popped "<<pop()<<endl;
	cout<<"Popped "<<pop()<<endl;
	cout<<"Popped "<<pop()<<endl;
	cout<<"Top "<<stck_top()<<endl;
	push(20);
	for(i=0;i<top;i++)
		cout<<arr[i]<<"\t";
	cout<<endl;
	if(is_empty())
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}