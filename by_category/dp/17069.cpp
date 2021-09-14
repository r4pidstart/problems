// https://www.acmicpc.net/problem/17069
// 2021-09-15 01:11:13 0ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > field(33, vector<int>(33, 0));
vector<vector<vector<long long> > > memo(33, vector<vector<long long> >(33, vector<long long>(3, -1)));
// 가로, 세로, 대각
long long dp(int x, int y, int d)
{
    if(x<1 || y<1) return 0;
    if(d==0 && (field[x][y] || field[x-1][y])) return memo[x][y][d]=0;
    if(d==1 && (field[x][y] || field[x][y-1])) return memo[x][y][d]=0;
    if(d==2 && (field[x][y] || field[x][y-1] || field[x-1][y] || field[x-1][y-1])) memo[x][y][d]=0;
    if(x==2 && y==1 && d==0) return memo[x][y][d]=1;
    if(memo[x][y][d] != -1) return memo[x][y][d];

    long long ret=0;
    if(d==0)
    {
        ret+=dp(x-1, y, 0);
        ret+=dp(x-1, y, 2);
    }
    else if(d==1)
    {
        ret+=dp(x, y-1, 1);
        ret+=dp(x, y-1, 2);
    }
    else if(d==2)
    {
        ret+=dp(x-1, y-1, 0);
        ret+=dp(x-1, y-1, 1);
        ret+=dp(x-1, y-1, 2);
    }

    return memo[x][y][d]=ret;
}

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d", &field[j][i]);

    printf("%lld", dp(n,n,0)+dp(n,n,1)+dp(n,n,2));
}

/*

*/