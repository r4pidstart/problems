// https://www.acmicpc.net/problem/25197
// 
#include"bits/stdc++.h"
using namespace std;

// Max value, 10000C2 doesn't exceed LLONG_MAX
long long get_combination(int n, int k)
{
    static vector<vector<long long> > memo(n+1, vector<long long>(k+1, -1));
    if(memo[n][k] != -1) 
        return memo[n][k];
    else if(n == k or k == 0)
        return 1;
    else if(n == 1)
        return n;
    
    return memo[n][k] = get_combination(n-1, k) + get_combination(n-1, k-1);
}

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    printf("%.6lf", get_combination(n, 2) / (double)k);
}

/*

*/