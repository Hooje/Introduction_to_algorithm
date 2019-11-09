#include<iostream>
using namespace std;

long long int A[10000000]={0};
long long int B[10000000]={0};
long long int solution(long long int ii);
long long int n;
int main()
{
	cin>>n;

	for (long long int i = 1; i <= n; ++i)
	{
		long long int x;
		cin>>x;
		A[i]=x;
		B[i]=x;
	}	
	cout<<max(solution(1), solution(2));
	return 0;
}

long long int solution(long long int ii)
{
	long long int in, out;
	if (ii==1)
	{
		in=A[1];
		out=0;
		long long int outnext=0;

		for (long long int i = 2; i < n; ++i)
		{
			outnext=max(in, out);
			in=out+A[i];
			out=outnext;
		}

	}
	if (ii==2)
	{
		in=A[2];
		out=0;
		long long int outnext=0;

		for (long long int i = 3; i <= n; ++i)
		{
			outnext=max(in, out);
			in=out+A[i];
			out=outnext;
		}
		
	}
	return max(in, out);
}