// https://www.acmicpc.net/problem/10538
// 2021-08-13 03:48:31 396ms
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000'007;

int main(void)
{
    int hp,wp,hm,wm; scanf("%d%d%d%d", &hp,&wp,&hm,&wm);
    vector<vector<char> > p(hp+1,vector<char>(wp+1)), m(hm+1, vector<char>(wm+1));

    for(int i=1; i<=hp; i++)
        for(int j=1; j<=wp; j++)
            scanf(" %c", &p[i][j]);
    for(int i=1; i<=hm; i++)
        for(int j=1; j<=wm; j++)
            scanf(" %c", &m[i][j]);

    vector<long long> pow_dp(hm*wm, 1);
    for(int i=1, l=hm*wm; i<l; i++)
        pow_dp[i]=(pow_dp[i-1]*33)%MOD;

    long long pat_hash=0;
    for(int i=1; i<=hp; i++)
        for(int j=1; j<=wp; j++)
            pat_hash=(pat_hash+p[i][j]*pow_dp[(i-1)*wm+(j-1)])%MOD;
    
    vector<vector<long long> > hashed(hm+1, vector<long long>(wm+1,0)), sum(hm+1, vector<long long>(wm+1,0));
    for(int i=1; i<=hm; i++)
        for(int j=1; j<=wm; j++)
            hashed[i][j]=m[i][j]*pow_dp[(i-1)*wm+(j-1)]%MOD;
    
    for(int i=1; i<=hm; i++)
        for(int j=1; j<=wm; j++)
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+hashed[i][j];

    int cnt=0;
    for(int i=1; i<=hm; i++)
        for(int j=1; j<=wm; j++)
        {
            int x=i-hp+1, y=j-wp+1;
            if(x<1 || y<1) continue;
            int debug=(i-hp)*wm+(j-wp);
            long long hash=pat_hash*pow_dp[debug]%MOD;
            long long target_hash=(sum[i][j]+sum[x-1][y-1]-sum[x-1][j]-sum[i][y-1])%MOD;
            if(hash==target_hash) cnt++;
        }

    printf("%d", cnt);
}

/*
    라빈카프 알고리즘
    https://codingdog.tistory.com/entry/%EB%9D%BC%EB%B9%88-%EC%B9%B4%ED%94%84-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B7%B8%EB%9E%98%EB%8F%84-%EB%B9%84%EB%B2%BC%EB%B3%BC-%EB%A7%8C%ED%95%9C-%EB%AC%B8%EC%A0%9C%EA%B0%80-%EC%9E%88%EB%8B%A4
*/