// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,l; scanf("%d%d", &n, &l);

    for(int i=l; i<=100; i++)
    {
        long double test = (long double)n/i + (long double)i/2 + 0.5;
        if(ceil(test) == test)
        {
            if((int)test-i < 0) continue;
            for(int j=(int)test-i; j<(int)test; j++)
                printf("%d ", j);
            return 0;
        }
    }
    printf("-1");
}

/*
    
*/