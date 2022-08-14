// https://www.acmicpc.net/problem/7795
// 2022-08-15 02:40:20 40ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m; scanf("%d%d", &n, &m);
        vector<int> a(n), b(m);
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        for(int i=0; i<m; i++)
            scanf("%d", &b[i]);
        sort(b.begin(), b.end());

        int cnt=0;
        for(int i : a)
        {
            auto it=lower_bound(b.begin(), b.end(), i);
            cnt+=it-b.begin();
        }
        printf("%d\n", cnt);
    }
}

/*
    
*/