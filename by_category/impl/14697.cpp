// https://www.acmicpc.net/problem/14697
// 2022-08-25 02:51:49 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d);
    for(int i=0; i*a<=d; i++)
        for(int j=0; j*b<=d; j++)
            for(int k=0; k*c<=d; k++)
                if(i*a + j*b + k*c == d)
                    return !printf("1");
    printf("0");
}

/*
    
*/