// https://www.acmicpc.net/problem/7570
// 2021-09-22 23:40:14 196ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> dp(1000001, 0);
    for(int i=0; i<n; i++)
    {
        int tmp; scanf("%d", &tmp);
        dp[tmp]=dp[tmp-1]+1;
    }
    printf("%d", n-*max_element(dp.begin(), dp.end()));
}

/*
    https://mygumi.tistory.com/276
*/