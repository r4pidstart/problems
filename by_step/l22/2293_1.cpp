// https://www.acmicpc.net/problem/2293
// 2021-04-04 22:14:08 48ms
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    vector<int> coins(1,0);
    for(int i=0; i<n; i++)
    {    
        int tmp; scanf("%d", &tmp);
        if(tmp<=k) // 주어진 동전으로 목표 가치를 만들 수 있을 경우
            coins.push_back(tmp);
    }
    int size = coins.size(), flag=0;
    int memo[2][k+1];
    memset(memo, 0, sizeof(int)*2*(k+1));
    memo[0][0]=1, memo[1][0]=1;
    
    for(int i=1; i<size; i++) // 사용 동전
    {
        if (flag==0) flag=1; else flag=0; // 두 줄만 사용
        memset(&memo[flag][1], 0, sizeof(int)*k);
        for(int j=1; j<=k; j++) // 만드는 가치
        {
            for(int l=0; l*coins[i]<=j; l++) // 사용 갯수
                memo[flag][j]+=memo[(flag+1)%2][j-l*coins[i]];
        }
    }

    printf("%d", flag ? memo[1][k]:memo[0][k]);
    return 0;
}