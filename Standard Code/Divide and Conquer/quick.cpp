#include <bits/stdc++.h>
using namespace std;
class Qsort
{
public:
	void qsort(int *,int ,int);
	int partition(int *,int ,int);
//	void print(int *,int);
};
int Qsort::partition(int *A,int start,int end)
{
	int i,pindex=start;
	int pivot=A[end];
	for(i=start;i<end;i++)
	{
		if(A[i]<=pivot)
		{
			swap(A[i],A[pindex]);
			pindex++;
		}
	}
	swap(A[pindex],A[end]);
	return pindex;
}
void Qsort::qsort(int *A,int start,int end)
{
	if(start<end)
	{
		int pindex=partition(A,start,end);
		qsort(A,start,pindex-1);
		qsort(A,pindex+1,end);
	}
}
/*void print(int *A,int n)
{
}*/
int main()
{
	Qsort obj;
	int n,*A,i;

	cin>>n;
	A=new int [sizeof(int)*n];
	for(i=0;i<n;i++)
		A[i]=rand()%1000-100;
	obj.qsort(A,0,n-1);
	for(i=0;i<n;i++)
	{
		cout<<A[i]<<"\t";
	}
	cout<<endl;
	return 0;
}