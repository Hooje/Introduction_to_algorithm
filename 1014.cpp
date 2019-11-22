#include <bits/stdc++.h>
using namespace std;

class obj
{
public:
	int value, first, end;
	obj(int v, int f, int e)
	{
		value=v;
		first=f;
		end=e;
	}
};

int n;
int A[2000000]={0};
int main()
{
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];
	}
	obj m(A[0], 0, 1);
	obj tem(A[0], 0, 1);
	for (int i = 1; i < n; ++i)
	{
		if (tem.value<0)
		{
			//cout<<" first "<< i<<endl;
			if (tem.value>m.value)
			{
				if (tem.value>m.value)
				{
					m=tem;
				}
			}
			tem=obj(A[i], i, i+1);
		}
		else
		{
			
				if (tem.value>m.value)
				{
					m=tem;
				}
				tem.value+=A[i];
				tem.end++;
				if (tem.value>m.value)
				{
					m=tem;
				}
			
			
		}
	}
	if (tem.value>m.value)
	{
		m=tem;
	}
	cout<<m.first<<" "<<m.end<<endl;
	return 0;
}