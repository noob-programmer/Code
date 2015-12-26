#include <bits/stdc++.h>
using namespace std;
void print(int Z[],int len_buffer,int sublen)
{
	int flag=1;
	for(int i=0;i<len_buffer;i++)
	{
		//cout<<Z[i]<<"\t";
		//cout<<endl;
		if(Z[i]==sublen)
		{
			flag=0;
			//cout<<"found ";
			cout<<(i-sublen-1)<<endl;
		}
	}
	if(flag==1)
	{
		cout<<endl;
	}
	
}
void Zalgo(string buffer,int sublen)
{
	int len_buffer=buffer.length();
	int Z[len_buffer];
	int left=0,right=0,k;
	for(k=1;k<len_buffer;k++)
	{
		if(k>right)
		{
			left=right=k;
			while(right<len_buffer && buffer[right]==buffer[right-left])
			{
				right++;
			}
			Z[k]=right-left;
			right--;
		}
		else
		{
			int k1=k-left;
			if(Z[k1]<right-k+1)
			{
				Z[k]=Z[k1];
			}
			else
			{
				left=k;
				while(right<len_buffer && buffer[right]==buffer[right-left])
				{
					right++;
				}
				Z[k]=right-left;
				right--;
			}
		}
	}
	print(Z,len_buffer,sublen);
}
int main()
{
	int sublen;
	cin>>sublen;
	string substring;
	cin>>substring;
	string input;
	cin>>input;	
	string buffer=substring+"$"+input;
	Zalgo(buffer,sublen);
	cout<<endl;
	return 0;
}