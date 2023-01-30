// https://www.acmicpc.net/problem/26152
// 2023-01-31 04:32:29
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int n; scanf("%d", &n);
	vector<int> upper(n), lower(n);
	for(int i=0; i<n; i++)
		scanf("%d", &upper[i]);
	for(int i=0; i<n; i++)
		scanf("%d", &lower[i]);
	
	int q; scanf("%d", &q);
	vector<pair<int, int> > query(q);
	for(int i=0; i<q; i++)
		scanf("%d", &query[i].first), query[i].second=i;
	sort(query.begin(), query.end(), greater<>());

	vector<int> _ans(q);
	int prev=0;
	long prev_space=LLONG_MAX;
	for(auto& it : query)
	{
		int& siz=it.first;
		if(prev_space < siz)
		{
			_ans[it.second]=prev;
			continue;
		}
		int lo=prev, hi=n, ans=0;
		long space=0;
		while(lo<=hi)
		{
			int mid=(lo+hi)/2;
			space=LLONG_MAX;
			for(int i=prev; i<mid; i++)
				space=min((long)upper[i]-lower[i], space);

			if(siz > space)
				hi=mid-1;
			else
				lo=mid+1, ans=mid;
		}
		_ans[it.second]=ans;
		prev_space=space;
		prev=ans;
	}
	for(auto& it : _ans)
		printf("%d\n", it);
}

/*
	
*/