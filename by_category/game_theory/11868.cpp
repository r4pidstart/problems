// https://www.acmicpc.net/problem/11868
// 2023-05-07 15:51:25
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    int ret=0;
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        ret^=a;
    }
    printf(ret ? "koosaga":"cubelover");
}

/*
    
*/