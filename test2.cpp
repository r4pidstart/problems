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
    int size = coins.size();
    int memo[size][k+1]={}; // index / sum
    for(int i=0; i<size; i++)
        memo[i][0]=1;
    
    for(int i=1; i<size; i++) // 사용 동전
        for(int j=1; j<=k; j++) // 만드는 가치
        {
            for(int l=0; l*coins[i]<=j; l++) // 사용 갯수
                memo[i][j]+=memo[i-1][j-l*coins[i]];
        }

    printf("%d", memo[size-1][k]);
    return 0;
}