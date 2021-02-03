#include<iostream>
using namespace std;
int main()
{
	int nSize,mSize;
	cin>>nSize;
	cin>>mSize;
	if(nSize>0 && nSize<1000000)
	{
		int n[nSize];
		int m[mSize];
		
		for(int i=0;i<nSize;i++)
		{
			cin>> n[i];
			cin>> m[i];
		}
		int count=0;
		cout<<endl;
		for(int i=0; i<nSize-1; i++)
		{
			if(m[i] == n[i+1])
			{
				count++;
			}
		}
		cout<<count<<endl;
		for(int i=0; i<nSize-1; i++)
		{
			if(m[i] == n[i+1])
			{
				cout<<n[i]<<" "<<m[i+1]<<endl;
			}
		}
	}

	return 0;
}
