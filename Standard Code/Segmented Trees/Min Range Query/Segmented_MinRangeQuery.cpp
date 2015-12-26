#include <bits/stdc++.h>
using namespace std;
int size,k;
int *segment;
int getsize(int N)
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


void constructTree(int input[],int segment[],int low,int high,int pos)
{
  if(low==high)
  {
    segment[pos]=input[low];
    return;
  }
  int mid=(low+high)/2;
  constructTree(input,segment,low,mid,2*pos+1);
  constructTree(input,segment,mid+1,high,2*pos+2);
  segment[pos]=min(segment[2*pos+1],segment[2*pos+2]);
}
void print()
{
  int i;
  for(i=0;i<size;i++)
    cout<<segment[i]<<"\t";
  cout<<endl;
}
int RangeQuery(int segment[],int qlow,int qhigh,int low,int high,int pos)
{
  if(qlow<=low && qhigh>=high)
    return segment[pos];
  else if (qlow>high || qhigh<low)
    return INT_MAX;
  
  int mid=(low+high)/2;
  return min(RangeQuery(segment,qlow,qhigh,low,mid,2*pos+1),
  RangeQuery(segment,qlow,qhigh,mid+1,high,2*pos+2));
  
}
int main()
{
  int arr[]={-1,2,4,0};
  int s_size=getsize(sizeof(arr)/sizeof(int));
  segment=new int[s_size];
  segment[s_size]={INT_MIN};
  constructTree(arr,segment,0,(sizeof(arr)/sizeof(int))-1,0);
  print();
  cout<<"RangeQuery is .. "<<RangeQuery(segment,1,3,0,3,0)<<endl;
  return 0;
}
