// https://www.acmicpc.net/problem/3056
// 2021-05-27 17:03:02 76ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    
    vector<double> dp(1<<n,0);
    vector<vector<int> > p(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &p[i][j]);
        
    dp[0]=1; // 성공확률 100%

    for(int i=0, l=1<<n; i<l; i++)
    {
        bitset<20> b=i; // n번째 비트 -> n번째 사람이 미션을 수행했는지 여부
        int next_task=b.count();
        for(int person=0; person<n; person++)
        {
            if(b[person]==0)
                dp[i|(1<<person)] = max(dp[i|(1<<person)], dp[i]*((double)p[person][next_task]/100));
        }
    } 
    printf("%lf", dp[(1<<n)-1]*100);
}