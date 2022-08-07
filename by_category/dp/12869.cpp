// https://www.acmicpc.net/problem/
// 2022-08-08 03:08:50 0ms
#include"bits/stdc++.h"
using namespace std;

int solution(int a, int b, int c)
{
    static vector<vector<vector<int> > > dp(a+1, vector<vector<int> >(b+1, vector<int>(c+1, -1)));

    if(a==0 and b==0 and c==0)
        return dp[0][0][0]=0;
    if(dp[a][b][c] != -1)
        return dp[a][b][c];

    int ret=INT32_MAX;

    ret=min(solution(max(0, a-9), max(0, b-3), max(0, c-1)), ret);
    ret=min(solution(max(0, a-9), max(0, b-1), max(0, c-3)), ret);
    ret=min(solution(max(0, a-3), max(0, b-9), max(0, c-1)), ret);
    ret=min(solution(max(0, a-1), max(0, b-9), max(0, c-3)), ret);
    ret=min(solution(max(0, a-3), max(0, b-1), max(0, c-9)), ret);
    ret=min(solution(max(0, a-1), max(0, b-3), max(0, c-9)), ret);
    
    return dp[a][b][c]=ret+1;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> hp(3);
    for(int i=0; i<n; i++)
        scanf("%d", &hp[i]);

    printf("%d", solution(hp[0], hp[1], hp[2]));

}

/*
    
*/