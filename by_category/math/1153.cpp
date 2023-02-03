// https://www.acmicpc.net/problem/1153
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	int n; scanf("%d", &n);
	// min -> 2+2+2+2
	if(n < 8)
		return !printf("-1");

	// if even -> 2+2+(a,b)
	// else odd -> 2+3+(a,b)

	vector<bool> prime_table(1000001, true);
	prime_table[0]=prime_table[1]=false;
	for(int i=2; i*i<=1000000; i++)
		for(int j=i+i; j<=1000000; j+=i)
			prime_table[j]=0;

	if(n&1)
		printf("%d %d ", 2, 3), n-=5;
	else
		printf("%d %d ", 2, 2), n-=4;

	for(int i=1; i<=n; i++)
		if(prime_table[i] and prime_table[n-i])
			return !printf("%d %d", i, n-i);
}

/*
	
*/