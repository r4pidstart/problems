// https://www.acmicpc.net/problem/2482
// 2021-05-30 00:58:47 344ms
#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000003

typedef long long ll;
int n,k;
vector<vector<vector<vector<ll> > > > memo;
// memo[위치][선택 갯수][선택여부][시작점]

ll dp(int i, int cnt, int now, int start)
{
    if(i>n-1)
        return 0; // 불가능한 경우
    if(cnt==k)
    {
        if(i==n-1) // 마지막을 체크했다면
            return start==1 ? 0:1;
        else
            return 1;
    }

    if(memo[i][cnt][now][start]!=-1)
        return memo[i][cnt][now][start];
    
    memo[i][cnt][now][start]=0;
    
    if(now==0)
    {
        memo[i][cnt][now][start]+=dp(i+1, cnt, 0, start);
        memo[i][cnt][now][start]+=dp(i+1, cnt+1, 1, start);
    }
    else
        memo[i][cnt][now][start]+=dp(i+1, cnt, 0, start);

    return memo[i][cnt][now][start]%MOD;
}

int main(void)
{
    scanf("%d%d", &n,&k);
    memo.assign(n, vector<vector<vector<ll> > >(k+1, vector<vector<ll> >(2,vector<ll>(2,-1))));
    printf("%lld", (dp(0,0,0,0)+dp(0,1,1,1))%MOD);
}