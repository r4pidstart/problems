// https://www.acmicpc.net/problem/2591
// 2023-04-17 23:56:20
#include"bits/stdc++.h"
using namespace std;

long solution(const string& s, int idx)
{
	static vector<long> memo(s.size()+1, -1);
	if(s.size() == idx) return 1;
	if(memo[idx] != -1) return memo[idx];

	long ret=0;

	// 1 to 34
	if(s[idx] and s[idx]!='0') ret+=solution(s, idx+1);
	int tmp=stoi(s.substr(idx, 2));
	if(10<=tmp and tmp<=34) ret+=solution(s, idx+2);

	return memo[idx]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
	string s; cin >> s;
	printf("%ld", solution(s, 0));
}

/*
	
*/