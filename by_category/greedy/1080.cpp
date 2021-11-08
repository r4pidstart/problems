// https://www.acmicpc.net/problem/1080
// 2021-11-08 23:27:04 0ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > matrix, original;

void change(int x, int y)
{
	for(int i=x; i<x+3; i++)
		for(int j=y; j<y+3; j++)
			matrix[i][j]^=1;
}

int main(void)
{
	int n,m; scanf("%d%d", &n,&m);
	matrix.assign(n, vector<int>(m,0));
	original.assign(n, vector<int>(m,0));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) scanf("%1d", &matrix[i][j]);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) scanf("%1d", &original[i][j]);

	int cnt=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(matrix[i][j]!=original[i][j]) 
			{
				if(j+2<m && i+2<n) change(i,j), cnt++;
				else return !printf("-1");
			}

	printf("%d", cnt);
}

/*
	
*/