// https://www.acmicpc.net/problem/14595
// 2024-03-22 21:36:08 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
	int n,m; scanf("%d%d", &n, &m);
	vector<pair<int, int> > arr(m);
	for(int i=0; i<m; i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	
	sort(arr.begin(), arr.end());

	int ans=n, idx=0;
	priority_queue<int, vector<int>, greater<> > pq;
	for(int i=1; i<=n; i++)
	{
		while(pq.size() and pq.top() < i)
			pq.pop();
		
		if(pq.size())
			ans--;

		while(idx<m and arr[idx].first==i)
			pq.push(arr[idx++].second);	
	}
	printf("%d", ans);
}

/*
	
*/