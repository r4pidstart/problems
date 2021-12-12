// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,a,b,cnt=1; scanf("%d%d%d", &n,&a,&b);
    while((a-1)/2 != (b-1)/2)
        a=(a-1)/2+1, b=(b-1)/2+1, cnt++;
    printf("%d", cnt);
}

/*
    
*/