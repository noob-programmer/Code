#include <bits/stdc++.h>
using namespace std;
bool ispair(char opening,char closing)
{
	if(opening == '(' && closing == ')')
		return true;
	else if(opening == '{' && closing == '}')
		return true;
	else if(opening == '[' && closing==']')
		return true;
		return false;
}
bool Arebalanced(string exp)
{
	int i;
	stack<char> S;
	for(i=0;i<exp.length();i++)
	{
		if(exp[i]== '(' || exp[i]== '{' ||exp[i]== '[')
			S.push(exp[i]);
		else if(exp[i]== ')' ||exp[i]== '}' ||exp[i]== ']')
		{
			if(S.empty() || !ispair(S.top(),exp[i]) )
			{
				return false;
			}
			else 
				S.pop();
		}
	}
	return S.empty()? true:false;
}
int main()
{
	string exp;
	cin>>exp;
	if(Arebalanced(exp))
	{
		cout<<"Success"<<endl;
	}
	else 
	{
		cout<<"faliure"<<endl;
	}
	return 0;
}