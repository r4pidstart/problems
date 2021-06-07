// https://www.acmicpc.net/problem/2482
// 2021-05-30 01:58:31 4ms
#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000003
typedef long long ll;

int n,k;
vector<vector<ll> > memo;
// memo[전체갯수][선택갯수]

ll dp(int tot, int cnt)
{
    if(cnt==1)
        return tot;
    if(cnt==0 || tot==cnt*2-1)
        return 1;
    if(tot<1 || tot<cnt*2-1)
        return 0;
    if(memo[tot][cnt]!=-1)
        return memo[tot][cnt];

    return memo[tot][cnt] = (dp(tot-1, cnt)+dp(tot-2, cnt-1))%MOD;
}

int main(void)
{
    scanf("%d%d", &n,&k);
    memo.assign(n, vector<ll>(k+1, -1));
    printf("%lld", (dp(n-1,k)+dp(n-3, k-1))%MOD);
}

// 첫 번째를 안 고른다면 dp(n-1,k)
// 첫 번째를 고른다면, 마지막과 두번째를 고를 수 없음 -> dp(n-3,k-1)