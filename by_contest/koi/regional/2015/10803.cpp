// https://www.acmicpc.net/problem/10803
// 2022-04-10 03:48:36 12ms
#include<bits/stdc++.h>
using namespace std;

int get_ans(int n, int m)
{
    static vector<vector<int> > memo(10001, vector<int>(101, -1));
    if(n < m) swap(n,m);

    if(memo[n][m] != -1)
        return memo[n][m];
    else if(n == m)
        return memo[n][m] = 1;
    else if(!n or !m)
        return 0;

    int ret=n*m;
    if(n >= 3 * m)
        return memo[n][m]=get_ans(n-m, m)+1;

    for(int mid=1; mid<=n/2; mid++)
        ret=min(ret, get_ans(mid, m) + get_ans(n-mid, m));
    for(int mid=1; mid<=m/2; mid++)
        ret=min(ret, get_ans(mid, n) + get_ans(m-mid, n));
    return memo[n][m]=ret;
}

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    printf("%d", get_ans(n, m));
}

/*
    
*/