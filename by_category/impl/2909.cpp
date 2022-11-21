// https://www.acmicpc.net/problem/2909
// 2022-11-22 04:02:49
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int c,k; scanf("%d%d", &c, &k);

    for(int i=0; i<k; i++)
    {
        if(c%10 > 4) c+=10;
        c/=10;
    }
    for(int i=0; i<k; i++)
        c*=10;
    printf("%d", c);
}

/*
    
*/