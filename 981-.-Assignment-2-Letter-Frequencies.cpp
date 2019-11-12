#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	int A[26]={0};
	int B[26]={0};
	cin>>s;

	for(int i=0; i<s.length(); i++)
	{
		A[s[i]-'A']++;
		B[s[i]-'A']++;
	}
	
	sort(A,A + 26);

	for (int i = 25; A[i]>0; i--)
	{
		for (int j = 0; j < 26 ; ++j)
		{
			if (A[i]==B[j])
			{
				cout<<j+65<<" "<<A[i]<<endl;
				B[j]=0;
				break;
			}
		}
	}


	return 0;
}
