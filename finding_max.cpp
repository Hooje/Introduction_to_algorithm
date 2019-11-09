#include <bits/stdc++.h>
using namespace std;

long long int cs(vector<long long int> &A, long long int ss, long long int se, long long int *st, long long int si);
void updatevalue(long long int *st, long long int ss, long long int se, long long int i, long long int si);
void update(vector<long long int> &A, long long int *st,  long long int n, long long int i, long long int x);

long long int query(long long int *st, long long int ss, long long int se, long long int qs, long long int qe, long long int si);

long long int node[10000000]={0};


int main()
{
	long long int x, j, k;
	long long int n, m;

	vector<long long int> A;
	cin>>n>>m;
	for (long long int i = 0; i < n; ++i)
	{
		cin>>x;
		A.push_back(x);
	}

//    long long int ce = (long long int)(ceil(log2(n)));
    long long int ms = 20000000;
	long long int *st = new long long int[ms];
	cs(A, 0, n-1, st, 0);
	for (long long int i = 0; i < m; ++i)
	{
		cin>>x>>j>>k;
		if (x==1)
		{
			//cout<<st[2];
			update(A, st, n, j, k);
			
		}
		if(x==2)
		{
			cout<<query(st, 0, n-1, j, k, 0)<<endl;
			//cout<<A[0]<<A[1]<<A[2];
		}
	}
	
	return 0;
}


long long int query(long long int *st, long long int ss, long long int se, long long int qs, long long int qe, long long int si)
{
	if (qs<=ss && qe>=se)
	{
		return st[si];
	}
	if (se<qs || ss>qe)
	{
		//important   because the range from -10000000
		return -1000000000;
	}
	long long int mid=(ss+se)/2;


	return max(query(st, ss, mid, qs, qe, 2*si+1), query(st, mid+1, se, qs, qe, 2*si+2));

}

long long int cs(vector<long long int> &A, long long int ss, long long int se, long long int *st, long long int si)
{
	if (ss==se)
	{
	
		st[si]=A[ss];
		node[ss]=si;
// cout<<si<<" "<<st[si]<<endl;
		return st[si];
	}
	
	long long int mid=(ss+se)/2;
 //cout<<si<<" "<<st[si]<<endl;
	st[si]=max(cs(A, ss, mid, st, si*2+1), cs(A, mid+1, se, st, si*2+2));
	//cout<<si<<" "<<st[si]<<endl;
	return st[si];
}
void updatevalue( long long int *st, long long int ss, long long int se, long long int i,long long int si)
{

	if (se!=ss)
	{
		long long int mid=(ss+se)/2;
		if (i>=ss && i <=mid)
		{
			updatevalue(st, ss, mid, i, 2*si+1);
		}
		else
			updatevalue(st, mid+1, se, i, 2*si+2);
		st[si]=max(st[2*si+1], st[2*si+2]);
	}
	return;
}
void update( vector<long long int> &A, long long int *st,  long long int n, long long int i, long long int x)
{
	A[i]=x;

	st[node[i]]=x;
	//cout<<node[i];
	updatevalue(st, 0, n-1, i, 0);

}