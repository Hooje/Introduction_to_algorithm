#include <iostream>
#include <queue>
using namespace std;

int main()
{
	//find smallest
	priority_queue<long long int, vector<int>, greater<int>> qu;
	long long int n, x, j, k;
	long long int ans=0;
	cin>>n;
	for (long long int i = 0; i < n; ++i)
	{
		cin>>x;
		qu.push(x);
	}

	for (;qu.size()>1;)
	{
		j=qu.top();
		qu.pop();
		k=qu.top();
		qu.pop();
		ans+=(j+k);
		qu.push(j+k);
	}

	cout<<ans%524287;



	/*long long int n;
	cin>>n;
	long long int A[500000]={0};
	for (long long int i = 0; i < n; ++i)
	{
		cin>>A[i];
	}
	sort(A, A+n);
	long long int ans=0;
	for (long long int i = 0; i < n; ++i)
	{
		ans+=A[i]*(n-i);
	}
	cout<<(ans-A[0])%524287;*/


}