int cs(vector<int> A, int ss, int se, vector<int> st, int si)
{
	if (ss=se)
	{
		st[si]=A[ss];
		return A[ss];
	}
	int mid=(ss+se)/2;
	st[si]=cs(A, ss, mid, st, si*2+1)+cs(A, mid+1, se, st, si*2+2);
	return st[si];
}
void updatevalue(vector<int> st, int ss, int se, int i, int diff, int si)
{
	if (i<ss||i>se)
	{
		return;
	}
	st[si]+=diff;
	if (se!=ss)
	{
		int mid=(ss+se)/2;
		updatevalue(st, ss, mid, i, diff, 2*si+1);
		updatevalue(st, mid+1, se, i, diff, 2*si+2);
		

	}
}
void update(vector<int>A, vector<int> st,  int n, int i, int x)
{
	int diff;
	diff=x-A[i];
	A[i]=x;
	updatevalue(st, 0, n-1, i, diff, 0)


}