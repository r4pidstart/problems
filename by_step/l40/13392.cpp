// https://www.acmicpc.net/problem/13392
// 2021-08-06 01:51:46 4ms
#include<bits/stdc++.h>
using namespace std;

int n;
string s1, s2;
vector<vector<int> > memo;
vector<vector<pair<int,int> > > route;
// route[nth][leftcnt]={prev turn, prev route}

int dp(int now, int leftcnt)
{
    if(now==n)
        return 0;

    if(memo[now][leftcnt]!=INT32_MAX/2) 
        return memo[now][leftcnt];

    int curr_num=(s1[now]+leftcnt)%10;
    int right=(curr_num-s2[now]+10)%10, left=(s2[now]-curr_num+10)%10;

    if(right+dp(now+1, leftcnt) < memo[now][leftcnt])
    {
        memo[now][leftcnt]=right+dp(now+1, leftcnt);
        route[now][leftcnt]={-right, leftcnt};
    }

    if(left+dp(now+1, (leftcnt+left)%10) < memo[now][leftcnt])
    {
        memo[now][leftcnt]=left+dp(now+1, (leftcnt+left)%10);
        route[now][leftcnt]={left, leftcnt};
    }
    
    return memo[now][leftcnt];
}

int main(void)
{
    scanf("%d", &n);
    cin>>s1>>s2;
    memo.assign(n, vector<int>(10, INT32_MAX/2));
    route.assign(n, vector<pair<int,int> >(10, {0,0}));

    for(int i=0; i<n; i++)
        s1[i]-='0', s2[i]-='0';

    printf("%d\n", dp(0,0));    
}

/*

*/