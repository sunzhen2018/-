#include<bits/stdc++.h>
using namespace std;
int data1[10];
bool f(int i)
{
	int t;
	while(i)
	{
		t=i%10;
		data1[t]--;
		if(data1[t]<0) {
			return false;
		}
		i/=10;
	}
	return true;
}
int main()
{
	for(int i=0;i<=9;i++)
	{
		data1[i]=2021;
	}
	for(int i=1;;i++)
	{
		int flag=f(i);
		if(flag==false)
		{
			cout<<i-1<<endl;
			break;
		}
	}
}
//3181
