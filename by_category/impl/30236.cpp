// https://www.acmicpc.net/problem/30236
// 2023-11-04 00:29:57
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<int> arr(n);
        int idx=1;
        for(int i=0; i<n; i++)
        {
            int a; scanf("%d", &a);
            if(a==idx) idx++;
            idx++;
        }
        printf("%d\n", idx-1);
    }
}

/*
    
*/