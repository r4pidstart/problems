// https://www.acmicpc.net/problem/20166
// 
#include"bits/stdc++.h"
using namespace std;

int count_word(int x, int y, int i, string s, vector<vector<char> >& table)
{
	if(i==s.size()-1) return 1;

	int ret=0;
	const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
	for(int w=0; w<8; w++)
	{
		int nx=(x+way[w][0]+table.size())%table.size(), ny=(y+way[w][1]+table[0].size())%table[0].size();
		if(table[nx][ny]==s[i+1])
			ret+=count_word(nx, ny, i+1, s, table);
	}
	return ret;
}

int get_ans(string s, vector<vector<char> >& table)
{
	static map<string, int> ma;
	if(ma.find(s) != ma.end()) return ma[s];
	int ret=0;
	for(int i=0; i<table.size(); i++)
		for(int j=0; j<table[0].size(); j++)
			if(table[i][j] == s[0])
				ret+=count_word(i, j, 0, s, table);
	return ma[s]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
	int n,m,k; scanf("%d%d%d", &n, &m, &k);
	vector<vector<char> > table(n, vector<char>(m));

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf(" %c", &table[i][j]);
	
	while(k--)
	{
		string s; cin >> s;
		printf("%d\n", get_ans(s, table));
	}
}

/*
	
*/