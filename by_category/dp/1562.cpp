// https://www.acmicpc.net/problem/1562
// 2021-06-07 09:54:05 4ms
#include<bits/stdc++.h>
using namespace std;

const int MOD=1000000000;
int memo[101][1024][10]={};
// total_digit, selected(bitmask), last_digit

int dp(int t_digit, int n_digit, int mask, int last)
{
    if(t_digit==n_digit)
        return mask==1023 ? 1:0;
    
    int& ret=memo[n_digit][mask][last];
    if(ret!=-1)
        return ret;

    ret=0;
    if(last+1==10) // 마지막 9일떄
        ret+=dp(t_digit, n_digit+1, mask|(1<<(last-1)), last-1);
    else if(last-1==-1) // 마지막 0일때
        ret+=dp(t_digit, n_digit+1, mask|(1<<(last+1)), last+1);
    else
    {
        ret+=dp(t_digit, n_digit+1, mask|(1<<(last-1)), last-1);
        ret+=dp(t_digit, n_digit+1, mask|(1<<(last+1)), last+1);
    }
    ret%=MOD;
    return ret;
}

int main(void)
{
    int n; scanf("%d", &n);
    int ans=0;
    memset(memo, -1, sizeof(int)*101*1024*10);
    for(int i=1; i<10; i++)
        ans=(ans+dp(n, 1, 1<<i, i))%MOD;
    printf("%d", ans);
}