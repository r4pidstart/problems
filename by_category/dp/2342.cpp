// https://www.acmicpc.net/problem/2342
// 2021-06-10 08:33:11 32ms
#include<bits/stdc++.h>
using namespace std;

vector<int> note;
// vector<vector<vector<int> > > memo;
int memo[100001][5][5];
int s;

int next(int a, int b)
{
    if(a==0)    return 2;
    if(a==b)    return 1;
    return 3+(a%2 == b%2);
}

int dp(int n, int a, int b)
{
    if(n==s-1)
        return 0;
    if(memo[n][a][b]!=-1)
        return memo[n][a][b];

    return memo[n][a][b]=min(dp(n+1, note[n], b)+next(a,note[n]), dp(n+1, a, note[n])+next(b,note[n]));
}

int main(void)
{
    int n=1;
    while(n!=0)
    {
        scanf("%d", &n);
        note.push_back(n);
        s++;
    }
    memset(memo, -1, sizeof(memo));
    // memo.assign(s+1, vector<vector<int> >(5, vector<int>(5, -1);
    printf("%d", dp(0,0,0));
}
