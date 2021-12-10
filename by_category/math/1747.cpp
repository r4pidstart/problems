// https://www.acmicpc.net/problem/1747
// 2021-12-11 00:10:10 28ms
#include<bits/stdc++.h>
using namespace std;

inline int check(string s)
{
	for(int i=0; i<s.length()/2; i++) if(s[i]!=s[s.length()-i-1]) return 0;
	return 1;
}

int main(void)
{
	vector<int> prime_table(1111112, 1);
	prime_table[1]=0;
	for(int i=2; i*i<=1111111; i++)
		for(int j=i+i; j<=1111111; j+=i)
			prime_table[j]=0;

	int n; scanf("%d", &n);
	for(int i=n; i<=1111111; i++)
		if(prime_table[i] and check(to_string(i))) return !printf("%d", i);
}

/*
	
*/