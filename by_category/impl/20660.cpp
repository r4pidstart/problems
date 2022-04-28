// https://www.acmicpc.net/problem/20660
// 2022-04-28 20:41:12 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	set<int> dislike;
	while(n--)
	{
		int a; scanf("%d", &a);
		dislike.insert(a);
	}

	int m, ans=0; scanf("%d", &m);
	while(m--)
	{
		int n; scanf("%d", &n);
		int flag=0;
		while(n--)
		{
			int a; scanf("%d", &a);
			if(dislike.find(a) != dislike.end())
				flag++;
		}
		if(!flag)
			ans++;
	}
	printf("%d", ans);
}

/*
	
*/