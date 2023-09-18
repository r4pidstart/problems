// https://www.acmicpc.net/problem/30017
// 2023-09-18 23:52:46
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int a,b; scanf("%d%d", &a, &b);
    int t=min(a-1, b);
    printf("%d", t+t+1);
}

/*
    
*/