// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int a,b; scanf("%d%d", &a,&b);
        printf("%d\n", lcm(a,b));
    }
}

/*
    
*/