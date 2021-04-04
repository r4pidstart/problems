// https://www.acmicpc.net/problem/2293
// 2021-04-04 22:25:15 0ms
#include<iostream>
#include<vector>
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

    
    int memo[k+1] = {};
    memo[0]=1;
    
    for(int i=1, size=coins.size(); i<size; i++) // 사용 동전
        for(int j=coins[i]; j<=k; j++) // 만드는 가치
            memo[j]+=memo[j-coins[i]];

    printf("%d", memo[k]);
    return 0;
}