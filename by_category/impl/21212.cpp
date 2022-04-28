// https://www.acmicpc.net/problem/21212
// 2022-04-28 19:44:55 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	int ans=INT32_MAX;
	while(n--)
	{
		int a,b; scanf("%d%d", &a, &b);
		ans=min(ans, b/a);
	}
	printf("%d", ans);
}

/*
	
*/