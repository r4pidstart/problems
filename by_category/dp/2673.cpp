// https://www.acmicpc.net/problem/2673
// 2022-03-19 05:40:45 0ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > memo(101, vector<int>(101, -1));
int dp(int s, int e, vector<vector<int> >& line)
{
    if(s==e) return 0;
    if(memo[s][e] != -1) return memo[s][e];

    int ret=line[s][e];
    for(int k=s+1; k<e; k++)
        ret=max(ret, dp(s,k, line)+dp(k,e, line)+line[s][e]);

    return memo[s][e]=ret;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > line(101, vector<int>(101,0));
    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        line[a][b]=line[b][a]=1;
    }

    printf("%d", dp(1, 100, line));
}

/*
    
*/