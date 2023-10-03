// https://www.acmicpc.net/problem/13199
// 2023-10-04 03:09:50
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int p,m,f,c; scanf("%d%d%d%d", &p, &m, &f, &c);
        
        int a1=(m/p) + (m/p*c)/f;
        int a2=m/p;
        if(m/p*c >= f)
            a2+=(m/p*c-f)/(f-c) + 1;

        printf("%d\n", a2-a1);
    }
}

/*
    
*/