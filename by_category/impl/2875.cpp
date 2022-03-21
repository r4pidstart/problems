// https://www.acmicpc.net/problem/2875
// 2022-03-22 00:03:37 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)

{
    int n,m,k; scanf("%d%d%d", &n, &m, &k);
    int cnt=0;
    while(n+m-3 >= k and n>1 and m)
        n-=2, m-=1, cnt++;
    printf("%d", cnt);
}

/*
    
*/