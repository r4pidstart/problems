// https://www.acmicpc.net/problem/9468
// 2023-12-07 00:26:42
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        int cnt=0, val=0;
        for(int i=0; i<15; i++)
        {
            int b; scanf("%d", &b); 
            if(b>val) cnt++;
            val=b;            
        }
        printf("%d %d\n", a, cnt);
    }
}

/*
    
*/