#include <bits/stdc++.h>
using namespace std;

class tree
{
public:
	tree(long long int a, long long int b)
	{
		this->a=a;
		this->b=b;
	}
	long long int a, b;
};
long long int recursion(tree root, tree aim);

int main()
{
	long long int n;
	cin>>n;
	while(n--)
	{
		tree root(0, 0), aim(0, 0);
		cin>>root.a>>root.b;
		cin>>aim.a>>aim.b;
		long long int ans=recursion(root, aim);
		if (ans<=0)
		{
			cout<<-1<<endl;
		}
		else 
			cout<<ans%524287<<endl;
	}
	return 0;
}

long long int recursion(tree root, tree aim)
{	
	if (aim.a<root.a||aim.b<root.b)
	{
		return -1;
	}
	
	if (aim.a==root.a&&aim.b==root.b)
	{
		return 1;
	}
	else if (aim.a>aim.b)
	{
		tree tem(aim.a-aim.b, aim.b);
		long long int ans;
		ans=recursion(root, tem);
		if(ans==-1)
		{
			return -1;
		}
		return (ans*2+1)%524287;
	}
	else if (aim.b>=aim.a)
	{
		tree tem(aim.a, aim.b-aim.a);
		long long int ans;
		ans=recursion(root, tem);
		if(ans==-1)
		{
			return -1;
		}
		return (ans*2)%524287;
	}
	else return 0;

}
