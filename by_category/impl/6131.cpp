 // https://www.acmicpc.net/problem/6131
// 2023-05-20 02:09:53
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int n; scanf("%d", &n);
	int cnt=0;
	for(int i=1; i<=500; i++)
		for(int j=1; j<=500; j++)
			if(i*i + n == j*j) cnt++;
	printf("%d", cnt);
}

/*
	
*/