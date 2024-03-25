// https://www.acmicpc.net/problem/3751
// 2024-03-24 21:57:30
#include"bits/stdc++.h"
using namespace std;

int dfs(const string& s, set<long>& se)
{
	if(s.size()==13)
		return 0;
	
	if(s.size())
		se.insert(stol(s));
	
	dfs(s+"4", se);
	dfs(s+"7", se);

	return 0;
}

int main(void)
{
	set<long> se;
	dfs("", se);

	set<long> cand(se);
	se.insert(0);

	while(true)
	{
		long cnt=cand.size();
		for(long i : cand)
		{	
			for(long j : se)
				if(__int128_t(i)*j < long(1e12))
					cand.insert(i*j);
				else
					break;
		}
		if(cand.size() == cnt)
			break;
	}

	vector<long> arr(cand.begin(), cand.end());

	int t; scanf("%d", &t);
	while(t--)
	{
		long a,b; scanf("%ld%ld", &a, &b);
		auto it1=lower_bound(arr.begin(), arr.end(), a);
		auto it2=upper_bound(arr.begin(), arr.end(), b);
		if(it1 != arr.begin())
			it1=prev(it1);
		printf("%ld\n", it2-it1-1);
	}
}

/*
	
*/