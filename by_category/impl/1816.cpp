// https://www.acmicpc.net/problem/1816
// 2022-12-16 22:53:36
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    while(n--)
    {
        long a; scanf("%ld", &a);
        int flag=0;
        for(int i=2; i<=1e6; i++)
            if(a%i == 0)
                flag=1;
        printf("%s\n", flag ? "NO":"YES");
    }

}

/*
    
*/