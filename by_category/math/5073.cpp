// https://www.acmicpc.net/problem/5073
// 2023-03-24 03:12:40  
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int a,b,c; scanf("%d%d%d", &a, &b, &c);
    while(a!=0 and b!=0 and c!=0)
    {
        if(a==b and b==c) printf("Equilateral\n");
        else if(a+b <= c or a+c <= b or b+c <= a) printf("Invalid\n");
        else if(a==b or b==c or a==c) printf("Isosceles\n");
        else printf("Scalene\n");
        scanf("%d%d%d", &a, &b, &c);
    }
}

/*
    
*/