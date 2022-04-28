// https://www.acmicpc.net/problem/4285
// 2022-04-28 20:33:23 44ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	while(true)
	{
		int n,m; scanf("%d", &n);
		if(!n) break;
		scanf("%d", &m);
		set<int> selected;
		while(n--)
		{
			int a; scanf("%d", &a);
			selected.insert(a);
		}

		int flag=0;
		while(m--)
		{
			int a,b; scanf("%d%d", &a, &b);
			while(a--)
			{
				int c; scanf("%d", &c);
				if(selected.find(c) != selected.end()) b--;
			}
			if(b>0) flag++;
		}
		printf("%s\n", flag ? "no":"yes");
	}
}

/*
	
*/