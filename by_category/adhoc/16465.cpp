// https://www.acmicpc.net/problem/16465
// 2023-06-02 02:57:27
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m,l; scanf("%d%d%d", &n, &m, &l);
    int len=0, tmp;
    for(int i=0; i<n; i++)
        scanf("%d", &tmp), len+=tmp;
    
    if(m==len) printf("0");
    else if(m<len) printf("-1");
    else if(l<=len or m-len>=l) printf("1");
    else printf("-1");
}

/*
    
*/