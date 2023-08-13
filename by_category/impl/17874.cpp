// https://www.acmicpc.net/problem/17874
// 2023-08-13 23:54:40
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,h,v; scanf("%d%d%d", &n, &h, &v);
    printf("%d", 4*max(n-h, h)*max(n-v, v));
}

/*
    
*/