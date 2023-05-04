// https://www.acmicpc.net/problem/1727
// 2023-05-04 13:21:14
#include"bits/stdc++.h"
using namespace std;

int dp(int n, int m, vector<int>& male, vector<int>& female)
{
    static vector<vector<int> > memo(n+1, vector<int>(m+1, -1));
    if(n<0 or m<0) return 0;
    if(memo[n][m] != -1) return memo[n][m];

    int ret=0;

    if(n==m) ret=dp(n-1, m-1, male, female)+abs(male[n]-female[m]);
    else ret=min(dp(n-1, m, male, female), dp(n-1, m-1, male, female)+abs(male[n]-female[m]));

    return memo[n][m]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<int> male(n), female(m);

    for(int i=0; i<n; i++)
        scanf("%d", &male[i]);
    for(int j=0; j<m; j++)
        scanf("%d", &female[j]);

    if(n<m)
        swap(n,m), swap(male, female);
    
    sort(male.begin(), male.end());
    sort(female.begin(), female.end());

    printf("%d", dp(n-1, m-1, male, female));
}

/*
    
*/