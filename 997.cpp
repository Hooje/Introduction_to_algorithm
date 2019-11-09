#include<iostream>
#include<memory.h>
#include<math.h>
using namespace std;
int n;
int sum=0, middle;
int A[1000]={0};
int value[1000]={0};
int solve(int k);
int dp[10000000];
int main()
{
 	cin>>n;
 	for (int i = 0; i < n; ++i)
 	{
 		int x;
 		cin>>x;
 		A[i]=x;
 		value[x]++;
 		sum+=x;
 	}
 	middle=sum/2;
 	for (int i = 0; i <=middle; ++i)
 	{
 		if (solve(middle+i)==1)
 		{
 			cout<<abs(sum-2*(middle+i))<<endl;
 			return 0;
 		}
 		if (solve(middle-i)==1)
 		{
 			cout<<abs(sum-2*(middle-i))<<endl;
 			return 0;
 		}
 	}
	return 0;
}

int solve(int k)
{
	memset(dp, -1, sizeof(dp));
	dp[0]=0;
	for (int i = 0; i <= 500 ; ++i)
	{
		if(value[i]!=0)
		{
			for (int j = 0; j <= k; ++j)
			{
				if (dp[j]>=0)
				{
					dp[j]=value[i];
				}
				else if (j<i || dp[j-i]<=0)
				{
					dp[j]=-1;
				}
				else
					dp[j]=dp[j-i]-1;

			}
		}
	}
	if (dp[k]>=0)
	{
		return 1;
	}
	return 0;
}