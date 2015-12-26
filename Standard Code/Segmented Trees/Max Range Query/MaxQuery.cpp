#include <bits/stdc++.h>
using namespace std;
long long int size,k;
long long int *segment;
long long int sum(long long int a,long long int b)
{
  return (a+b);
}
long long int getsize(long long int N)
{
  size=1;

  for(;size<=N;size<<=1);
  if((N & N-1) == 0)
  {
    size=(size)-1;
    return size;
  }
 else 
    return size;
}


/*SegmentTrees(int arr[],int N)
{
  k=getsize(N);
  segment=new int[k];
  segment[]={ INT_MAX };
  constructTree(arr,segment,0,k-1,0);
}*/


void constructTree(long long int input[],long long int segment[],long long int low,long long int high,long long int pos)
{
  if(low==high)
  {
    segment[pos]=input[low];
    return;
  }
  long long int mid=(low+high)/2;
  constructTree(input,segment,low,mid,2*pos+1);
  constructTree(input,segment,mid+1,high,2*pos+2);
  segment[pos]=(max(segment[2*pos+1],segment[2*pos+2]));
}
void print()
{
  long long int i;
  for(i=0;i<size;i++)
    cout<<segment[i]<<"\t";
  cout<<endl;
}
long long int RangeQuery(long long int segment[],long long int qlow,long long int qhigh,long long int low,long long int high,long long int pos)
{
  if(qlow<=low && qhigh>=high)
    return segment[pos];
  else if (qlow>high || qhigh<low)
    return INT_MIN;
  
  long long int mid=(low+high)/2;
  /*return max(max(RangeQuery(segment,qlow,qhigh,low,mid,2*pos+1),
  RangeQuery(segment,qlow,qhigh,mid+1,high,2*pos+2)),sum(RangeQuery(segment,qlow,qhigh,low,mid,2*pos+1),
  RangeQuery(segment,qlow,qhigh,mid+1,high,2*pos+2)));*/
  return max(RangeQuery(segment,qlow,qhigh,low,mid,2*pos+1),
  RangeQuery(segment,qlow,qhigh,mid+1,high,2*pos+2));
}
int main()
{
  int n,i;
  cin>>n;
  long long int arr[n];
  for(i=0;i<n;i++)
    cin>>arr[i];
  int s_size=getsize(n);
  segment=new long long int[s_size];
  int m;
  cin>>m;
  for(i=0;i<m;i++)
  {
    int q1,q2;
    segment[s_size]={INT_MIN};
    cin>>q1>>q2;
    constructTree(arr,segment,0,n-1,0);
    cout<<RangeQuery(segment,q1-1,q2-1,0,n-1,0)<<endl;
  }
  return 0;
}