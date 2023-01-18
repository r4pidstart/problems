// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	long s, t; scanf("%ld%ld", &s, &t);

	if(s==t)
		return !printf("0");

	set<int> visited;
	queue<pair<long, string> > q;
	q.push({s, ""});
	visited.insert(s);

	while(q.size())
	{
		long now=q.front().first;
		string nows=q.front().second;
		q.pop();

		if(now==t)
			return (cout << nows, 0);

		if(abs(now*now) < INT32_MAX and visited.find(now*now) == visited.end())
			q.push({now*now, nows+'*'}), visited.insert(now*now);
		
		if(abs(now+now) < INT32_MAX and visited.find(now+now) == visited.end())
			q.push({now+now, nows+'+'}), visited.insert(now+now);

		if(abs(now-now) < INT32_MAX and visited.find(now-now) == visited.end())
			q.push({now-now, nows+'-'}), visited.insert(now-now);

		if(now and abs(now/now) < INT32_MAX and visited.find(now/now) == visited.end())
			q.push({now/now, nows+'/'}), visited.insert(now/now);
	}
	printf("-1");
}

/*
	
*/