// https://www.acmicpc.net/problem/4796
// 2021-11-07 01:16:36 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    for(int i=0; i<INT32_MAX; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        if(!a and !b and !c) return 0;
        printf("Case %d: %d\n", i+1, c/b*a + min(c-c/b*b, a)); 
    }
}

/*
    
*/