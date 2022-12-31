// https://www.acmicpc.net/problem/1750
// 2022-12-31 20:59:28
#include"bits/stdc++.h"
using namespace std;

const int MOD=10'000'003;
int solution(int now, int tmp, vector<int>& arr)
{
    static vector<vector<int> > dp(arr.size()+1, vector<int>(100001, -1));

    if(now < 0)
        return tmp==1;    

    if(dp[now][tmp] != -1)
        return dp[now][tmp];
    
    int ret=0;
    ret+=solution(now-1, tmp, arr);
    ret+=solution(now-1, gcd(tmp, arr[now]), arr);

    return dp[now][tmp]=ret%MOD;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)  
        scanf("%d", &arr[i]);
    printf("%d", solution(n-1, 0, arr));
}

/*
    
*/