// https://www.acmicpc.net/problem/11062
// 2021-09-12 01:41:46 108ms
#include<bits/stdc++.h>
using namespace std;

int n; 
vector<int> cards;
vector<vector<int> > memo;

int dp(int turn, int l, int r)
{
    if(l==r)
    {
        if(turn) return cards[l];
        else return 0;
    }

    if(memo[l][r] != -1) return memo[l][r];

    int ret=0;
    if(turn) // 내 차례일땐 최대로
        ret=max(dp(turn^1, l+1, r)+cards[l], dp(turn^1, l, r-1)+cards[r]);
    else // 상대 차례일땐 최소로
        ret=min(dp(turn^1, l+1, r), dp(turn^1, l, r-1));
    return memo[l][r]=ret;
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        cards.assign(n,0);
        for(int i=0; i<n; i++)
            scanf("%d", &cards[i]);
        memo=vector<vector<int> >(n, vector<int>(n,-1));
        printf("%d\n", dp(1, 0, n-1));
    }
}

/*

*/