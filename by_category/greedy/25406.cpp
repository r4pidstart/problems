// https://www.acmicpc.net/problem/25406
// 2023-02-05 04:05:35
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int n; scanf("%d", &n);
	vector<list<int> > arr(n+1);
	for(int i=0; i<n; i++)
	{
		int a; scanf("%d", &a);
		arr[a].push_back(i+1);
	}

	// first value, iterator
	priority_queue<pair<int, vector<list<int> >::iterator>, 
			vector<pair<int, vector<list<int> >::iterator> >, greater<> > pq;
	
	// size, iterator
	set<pair<int, vector<list<int> >::iterator>, greater<> > se;

	for(int i=1; i<=n; i++)
		if(arr[i].size())
			pq.push({arr[i].front(), arr.begin()+i}), 
			se.insert({arr[i].size(), arr.begin()+i});
	
	int prev=-1;
	vector<int> ans;
	while(n--)
	{
		if(se.begin()->first > (n+1)/2)
		{
			auto [cnt, it]=*se.begin();
			se.erase(se.begin());

			if(prev == distance(arr.begin(), it))
				return !printf("-1");
			prev=distance(arr.begin(), it);
			ans.push_back(it->front());
			it->pop_front();

			if(it->size())
				se.insert({it->size(), it});
		}
		else
		{

			while(true)
			{
				auto [val, it]=pq.top();
				if(val == it->front()) break;
				else
				{
					pq.pop();
					pq.push({it->front(), it});
				}
			}

			auto [val, it]=pq.top();
			pq.pop();
			if(prev == distance(arr.begin(), it))
			{
				if(!pq.size())
					return !printf("-1");

				while(true)
				{
					auto [val, it]=pq.top();
					if(val == it->front()) break;
					else
					{
						pq.pop();
						pq.push({it->front(), it});
					}
				}

				auto [val2, it2]=pq.top();
				prev=distance(arr.begin(), it2);
				pq.pop();
				pq.push({it->front(), it});

				ans.push_back(val2);
				se.erase({it2->size(), it2});
				it2->pop_front();
				if(it2->size())
				{
					se.insert({it2->size(), it2});
					pq.push({it2->front(), it2});
				}
			}
			else
			{
				prev=distance(arr.begin(), it);

				ans.push_back(val);
				se.erase({it->size(), it});
				it->pop_front();
				if(it->size())
				{
					se.insert({it->size(), it});
					pq.push({it->front(), it});
				}
			}
		}
	}
	for(auto i : ans)
		printf("%d ", i);
}

/*
	
*/