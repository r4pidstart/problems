// https://www.acmicpc.net/problem/12996
// 2023-10-03 01:24:58
#include"bits/stdc++.h"
using namespace std;

int sol(int n, int a, int b, int c)
{
    // a b c ab bc ac abc
    static vector<vector<vector<vector<int> > > > memo(n+1, vector<vector<vector<int> > >(n+1, vector<vector<int> >(n+1, vector<int>(n+1, -1))));
    
    if(n==0) return !(a+b+c);
    if(memo[n][a][b][c] != -1) return memo[n][a][b][c];
    
    long ret=0;
    if(a) ret+=sol(n-1, a-1, b, c);
    if(b) ret+=sol(n-1, a, b-1, c);
    if(c) ret+=sol(n-1, a, b, c-1);
    if(a and b) ret+=sol(n-1, a-1, b-1, c);
    if(a and c) ret+=sol(n-1, a-1, b, c-1);
    if(b and c) ret+=sol(n-1, a, b-1, c-1);
    if(a and b and c) ret+=sol(n-1, a-1, b-1, c-1);
    
    return memo[n][a][b][c]=ret%1'000'000'007;
}
int main(void)
{
#ifdef LOCAL
#endif
    int n,a,b,c; scanf("%d%d%d%d", &n, &a, &b, &c);
    printf("%d", sol(n, a, b, c));
}

/*
*/