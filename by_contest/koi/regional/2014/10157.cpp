// https://www.acmicpc.net/problem/10157
// 2022-04-30 03:52:26 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n,m,k; scanf("%d%d%d", &n, &m, &k);
	if(n*m < k) return !printf("0");

	k--;
	int x=0, y=0;
	while((n+m-2-x-x-y-y)*2 <= k)
		k-=(n+m-2-x-x-y-y)*2, x++, y++;

	int x_min=x, x_max=n-x-1, y_min=y, y_max=m-y-1;
	while(k--)
	{
		if(x==x_min and y!=y_max) y++;
		else if(x==x_min and y==y_max) x++;
		else if(y==y_max and x!=x_max) x++;
		else if(y==y_max and x==x_max) y--;
		else if(y!=y_min and x==x_max) y--;
		else if(y==y_min and x==x_max) x--;
		else if(y==y_min and x!=x_min) x--;
	}
	printf("%d %d", x+1, y+1);
}

/*
	
*/