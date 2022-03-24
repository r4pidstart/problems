// https://www.acmicpc.net/problem/10101
// 2022-03-25 00:01:26 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a,b,c; scanf("%d%d%d", &a, &b, &c);
    if(a==b and b==c and b==60) printf("Equilateral");
    else if(a+b+c == 180 and (a==b or b==c or a==c)) printf("Isosceles");
    else if(a+b+c == 180) printf("Scalene");
    else printf("Error");
}

/*
    
*/