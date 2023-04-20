// https://www.acmicpc.net/problem/12969
// 2023-04-20 19:50:35
#include"bits/stdc++.h"
using namespace std;

string dp(int len, int cnt, int a, int b, int n, int m, string& s)
{
	static vector<vector<vector<vector<int> > > > memo(31, vector<vector<vector<int> > >(436, vector<vector<int> >(31, vector<int>(31, -1))));
	if(len==n)
	{
		if(cnt==m) return s;
		else return string(1, 127);
	}
	if(cnt>m or memo[len][cnt][a][b] != -1) return string(1, 127);
	memo[len][cnt][a][b]=1;

	string ret=string(1, 127);

	// append c
	s+='C';
	ret=dp(len+1, cnt+a+b, a, b, n, m, s);
	if(ret != string(1, 127)) return ret;
	s.pop_back();

	// append b
	s+='B';
	ret=dp(len+1, cnt+a, a, b+1, n, m, s);
	if(ret != string(1, 127)) return ret;
	s.pop_back();

	// append a
	s+='A';
	ret=dp(len+1, cnt, a+1, b, n, m, s);
	if(ret != string(1, 127)) return ret;
	s.pop_back();

	return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
	int n,m; scanf("%d%d", &n, &m);
	string s="";
	s=dp(0, 0, 0, 0, n, m, s);
	cout << (s != string(1, 127) ? s:"-1");
}

/*
	
*/