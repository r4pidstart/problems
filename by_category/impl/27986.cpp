// https://www.acmicpc.net/problem/27986
// 2023-05-03 02:35:46
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);

    int k=INT32_MAX;
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        k=min(k, b-a+1);
    }

    int target=0;
    for(int i=0; i<n; i++)
    {
        printf("%d ", target+1);
        target=(target+1)%k;
    }
}

/*
    
*/