// https://www.acmicpc.net/problem/4375
// 2022-12-31 19:20:05
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; 
    while (~scanf("%d", &n))
    {
        int cnt=1, tmp=1;
        while(tmp % n)
        {
            cnt++;
            tmp=(tmp*10+1)%n;
        }
        printf("%d\n", cnt);
    }
}

/*
    
*/