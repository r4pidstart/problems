// https://www.acmicpc.net/problem/1176
// 2021-10-12 01:39:24 44ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,dif; scanf("%d%d", &n,&dif);
    vector<int> student(n,0);
    for(int i=0; i<n; i++) scanf("%d", &student[i]);

    vector<vector<long long> > dp(n, vector<long long>((1<<n)+1, 0));
    // 마지막 학생, 고른 학생

    for(int i=0; i<n; i++)
        dp[i][1<<i]=1;

    for(int i=0; i<dp[0].size(); i++) 
        for(int j=0; j<n; j++) // 지난 번 마지막으로 골라진 학생
        {
            if(!dp[j][i]) continue;
            for(int k=0; k<n; k++) // 이번에 고를 학생
            {
                if(i&(1<<k)) continue;
                if(abs(student[j]-student[k]) > dif) dp[k][i|(1<<k)]+=dp[j][i];
            }
        }

    long long ans=0;
    for(int i=0; i<n; i++)
        ans+=dp[i][(1<<n)-1];

    printf("%lld", ans);
}

/*
    
*/