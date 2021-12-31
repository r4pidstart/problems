// https://www.acmicpc.net/problem/1408
// 2022-01-01 05:45:25 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a,b,c,d,e,f; scanf("%d:%d:%d\n%d:%d:%d", &a,&b,&c,&d,&e,&f);
    int g=0, h=0, i=0;
    while(a!=d or b!=e or c!=f)
    {
        c++, i++;

        if(c==60) c=0, b++;
        if(b==60) b=0, a++;
        if(a==24) a=0;
        
        if(i==60) i=0, h++;
        if(h==60) h=0, g++;
    }
    printf("%02d:%02d:%02d", g,h,i);
}

/*
    
*/