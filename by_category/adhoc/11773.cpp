// https://www.acmicpc.net/problem/11773	
// 2023-05-22 00:30:18
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
	string s="abcdefghi";
	int a,b; scanf("%d%d", &a, &b);
	while(a--)
	{
		printf("%s ", s.c_str());
		next_permutation(s.begin(), s.end());
	}
}

/*
	
*/