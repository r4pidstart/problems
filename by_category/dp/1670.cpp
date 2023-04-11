// https://www.acmicpc.net/problem/1670
// 2023-04-12 00:28:20
#include"bits/stdc++.h"
using namespace std;

long solution(int n)
{
    static vector<int> memo(n+1, -1);
    if(n<=2) return 1;
    if(memo[n] != -1) return memo[n];

    long ret=0; 
    // a ㅁㅁㅁㅁㅁㅁ b
    for(int i=0; i<=n-2; i+=2)
        ret=(ret+solution(i)*solution(n-2-i))%987654321; 

    return memo[n]=ret;
}
int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    printf("%d", solution(n));
}

/*
    
*/