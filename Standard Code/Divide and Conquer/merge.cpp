#include <bits/stdc++.h>
using namespace std;
class Merge_class
{
	public:
		void merge(int a[],int L[],int len_left,int R[],int len_right);	
		void merge_sort(int a[],int n);
};
void Merge_class::merge(int a[],int L[],int len_left,int R[],int len_right)
{
    int i=0,j=0,k=0;
    while(i<len_left && j<len_right)
    {
        if( L[i] < R[j] )
        {
            a[k++]=L[i++];
        }
        else
        {
            a[k++]=R[j++];
        }
    }
    while(i<len_left)
    {
        a[k++]=L[i++];
    }
    while(j<len_right)
    {
        a[k++]=R[j++];
    }
    return;

}
void Merge_class::merge_sort(int a[],int n)
{
    int mid,i;
    int *L,*R;
    if(n<2)
        return;
    mid=n/2;

    L=(int *)malloc(mid*sizeof(int));
    R=(int *)malloc((n-mid)*sizeof(int));
    for(i=0;i<mid;i++)
    {
        L[i]=a[i];
    }
    for(i=mid;i<n;i++)
    {
        R[i-mid]=a[i];
    }
    merge_sort(L,mid);
    merge_sort(R,n-mid);
    merge(a,L,mid,R,n-mid);
}
int main()
{
	Merge_class obj;
    int a[10],n,i;
    printf("enter array count\n");
    scanf("%d",&n);
    printf("enter the array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
   // n=(sizeof(a)/sizeof(int));
    obj.merge_sort(a,n);
    printf("the sorted array is.....\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}

