// https://acmicpc.net/problem/16916
// 2021-08-15 04:18:53 84ms
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
	string parent, pattern;
	cin >> parent >> pattern;

	vector<int> pi(pattern.length(),0);
	int parentSize=parent.length(), patternSize=pattern.length();

	// make failure function
	for(int i=1, j=0; i<patternSize; i++)
	{
		while(j>0 && pattern[i]!=pattern[j])
			j=pi[j-1];

		if(pattern[i]==pattern[j])
			pi[i]=++j;
	}

	int ans=0;
	// kmp
	for(int i=0, j=0; i<parentSize; i++)
	{
		while(j>0 && parent[i]!=pattern[j])
			j=pi[j-1];
		
		if(parent[i]==pattern[j])
		{
			if(j==patternSize-1)
			{
				ans++;
				j=pi[j];
			}
			else
				j++;
		}
	}
	ans=ans?1:0;
    cout << ans;
	return 0;
}