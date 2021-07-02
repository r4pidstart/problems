// https://www.acmicpc.net/problem/1029
// 2021-07-03 00:21:42 64ms
#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > sell_price;
vector<vector<vector<int> > > dp;
// dp[mask][price][now]: 최대 명수

int main(void)
{
    scanf("%d", &n);
    dp.assign(1<<n, vector<vector<int> >(10, vector<int>(n+1, 0)));
    sell_price.assign(n+1, vector<int>(n+1, 0));
    // for(int i=0; i<n; i++)
    //     for(int j=0; j<n; j++)
    //         scanf("\n %c", &sell_price[i][j]);
    
    // for(int i=0; i<n; i++)
    //     for(int j=0; j<n; j++)
    //         sell_price[i][j]-='0';
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%1d", &sell_price[i][j]);

    int ans=0;
    dp[1][0][0]=1;
    for(int mask=1, l=1<<n; mask<l; mask++)
        for(int price=0; price<10; price++)
            for(int now=0; now<n; now++)
            {
                if(!dp[mask][price][now]) continue; // 경우의 수가 없을경우
                for(int next=0; next<n; next++)
                {
                    if(mask&(1<<next)) continue; // 이미 거친 사람일경우
                    if(price > sell_price[now][next]) continue; // 판매가가 더 싼 가격일 경우

                    int new_mask=mask|(1<<next), new_price=sell_price[now][next];
                    dp[new_mask][new_price][next]=max(dp[new_mask][new_price][next], dp[mask][price][now]+1);
                    ans=max(ans, dp[new_mask][new_price][next]);
                }
            }
    printf("%d", ans);
}

/*
    2<=N<=15 -> bit dp?
*/