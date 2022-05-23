// https://www.acmicpc.net/problem/2600
// 2022-05-24 02:46:25 4ms
#include"bits/stdc++.h"
using namespace std;

int ans(int a, int b, vector<vector<int> > &dp, int q=0, int w=0, int e=0)
{
    static int cnt[3]={q, w, e};

    if(dp[a][b] != -1) return dp[a][b];

    for(int i=0; i<3; i++)
    {
        if((a-cnt[i] >= 0 and !ans(a-cnt[i], b, dp)) or (b-cnt[i] >= 0 and !ans(a, b-cnt[i], dp))) 
            return dp[a][b]=1;
    }
    return dp[a][b]=0; // 상대방이 지는 경우가 있다면 이기는 거고, 없다면 지는 거임.
}

int main(void)
{
    int cnt[3]; scanf("%d%d%d", &cnt[0], &cnt[1], &cnt[2]);
    sort(cnt, cnt+3);
    vector<vector<int> > dp(501, vector<int>(501, -1));
    for(int i=0; i<5; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        printf("%c\n", ans(a, b, dp, cnt[0], cnt[1], cnt[2]) ? 'A':'B');
    }
}

/*
    
*/