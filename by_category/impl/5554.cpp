// https://www.acmicpc.net/problem/5554
//  2022-03-22 21:33:36 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d);
    int y=a+b+c+d;
    printf("%d\n%d", y/60, y%60);
}

/*
    
*/