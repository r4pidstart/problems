// https://www.acmicpc.net/problem/16953
// 2021-11-08 22:59:12 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int a,b,cnt=0; scanf("%d%d", &a,&b);
	while(a<b)
	{
		if(b%10==1 && a<=b/10) b/=10;
		else if(!(b&1)) b/=2;
		else break;
		cnt++;
	}
	if(a!=b) printf("-1");
	else printf("%d", cnt+1);
}

/*
	
*/