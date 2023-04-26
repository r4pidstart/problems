// https://www.acmicpc.net/problem/15922
// 2023-04-26 20:02:06
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    
    int len=0, prev=INT32_MIN;
    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        if(b < prev) continue;
        len+=b-max(prev, a);
        // printf("--%d %d %d\n", b, max(prev, a), len);
        prev=b;
    }
    printf("%d", len);
}

/*
    
*/