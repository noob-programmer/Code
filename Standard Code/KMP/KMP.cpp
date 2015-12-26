#include<bits/stdc++.h>
using namespace std;
int *output,size;
void PrefixArray(char substring[],int len)
{
	int i=1,j=0;
	
	output=new int[sizeof(int)*len];
	output[len]={0};
	while(i<len)
	{
		if(substring[i]==substring[j])
		{
			output[i]=j+1;
			i++;j++;
		}
		else
		{
			if(j!=0)
			{
				j=output[j-1];
					
			}
			else
			{
				output[i]=0;
				i++;
			}
		}
	}
	
}
void print(int len)
{
	int i;
	for(i=0;i<len;i++)
		cout<<output[i]<<"\t";
	cout<<endl;
}
void KMP(char input[],char substring[],int inlength,int len)
{
	
	PrefixArray(substring,len);
	int i=0,j=0,flag=0;
	while(i<inlength && j<len)
	{
		if(input[i]==substring[j])
		{
			i++;
			j++;
		} 
		else
		{
			if(j!=0)
			{
				j=output[j-1];
			}
			else
			{
				i++;
			}
		}
		if(j==len)
		{
			flag=1;
			cout<<(i-len)<<endl;
			i=(i-len+1);
			j=0;
		}
	}
	if(flag==0)
	{
		cout<<endl;
	}
	//return cnt;
}
int main()
{
	int len;
	cin>>len;
	char input[5000000];
	
	char substring[len];
	cin>>substring;
	cin>>input;
	int inlength=strlen(input);
	KMP(input,substring,inlength,len);
	cout<<endl;
	//PrefixArray(substring);
	print(len); 
	return 0;
}