#include <iostream>
#include <algorithm>
#define strange 38759524
using namespace std;
int cc=0;
int binarysearch(int x, int i, int j, int n);
int A[3000]={0};
class two
{
public:
		two(int x=0, int y=0, int z=0)
		{ value=x; a=y; b=z;};
		int value;
		int a;
		int b;
		bool operator <(const two &t)const
		{
			return value<t.value;
		}
};
two twoplus[10000000]; 
int main()
{
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];

	}
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n ; ++j)
		{
			/*if (i==j)
			{
			twoplus[n*i+j]=strange;
			}*/
			twoplus[cc].value=A[i]+A[j];
			twoplus[cc].a=i;
			twoplus[cc].b=j;
			cc++;
		}
	}
	sort(twoplus, twoplus+cc);
	int ans;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			ans=binarysearch(-A[i]-A[j], i, j, n);
			if (ans==1)
			{
				cout<<1;
				return 0;
			}
		}
	}
	if (ans==1)
	{
		cout<<1;
		return 0;
	}
	else 
		cout<<0;
	
	return 0;
}

int binarysearch(int x, int i, int j, int n)
{
	int left=0;
	int right=cc;
	/*for (int i = 0; i < cc ; ++i)
	{
		
	}
	for (int b = 0; b < n; ++b)
	{
		if (x==A[j]+A[b])
		{
			return 0;
		}
	}
	*/
	/*for (int i = 0; i < 16; ++i)
	{
		cout<<twoplus[i]<<endl;
	}*/
	while(right>left)
	{
		int middle=(left+right)/2;
		if (twoplus[middle].value==x)
		{
			if (twoplus[middle].a==i||twoplus[middle].b==j)
			{
				int m=middle;
				for (int k = m+1; k < cc; ++k)
				{
					if (twoplus[k].value!=x)
					{
						break;
					}
					else if (twoplus[k].a!=i&&twoplus[k].b!=j)
					{
						return 1;
					}
				}
				for (int k = m-1; k >0 ; --k)
				{
					if (twoplus[k].value!=x)
					{
						break;
					}
					else if (twoplus[k].a!=i&&twoplus[k].b!=j)
					{
						return 1;
					}
				}
				return 0;
			}
			 return 1;
		}
		else if (twoplus[middle].value<x)
		{
			left=middle+1;
		}
		else right=middle-1;
	}
	return 0;
}