// https://www.acmicpc.net/problem/28438
// 2023-12-20 01:30:52
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m,q; scanf("%d%d%d", &n, &m, &q);
    vector<int> row_sum(n), col_sum(m);

    for(int i=0; i<q; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        if(a==1)
            row_sum[b-1]+=c;
        else
            col_sum[b-1]+=c;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            printf("%d ", row_sum[i]+col_sum[j]);
        printf("\n");
    }
}

/*
    
*/