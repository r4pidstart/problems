// https://www.acmicpc.net/problem/15831
// 2023-04-12 21:14:07
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int n, b, w; scanf("%d%d%d", &n, &b, &w);
	string s; cin >> s;

	int ans=0, lo=0, hi=0; 
	int black=0, white=0;
	while(hi <= n)
	{
		if(black <= b and white >= w)
			ans=max(ans, hi-lo);
		if(black > b)
		{
			if(s[lo++]=='B') black--;
			else white--;
		}
		else
		{
			if(s[hi++]=='B') black++;
			else white++;
		}
	}
	printf("%d", ans);
}

/*
	
*/