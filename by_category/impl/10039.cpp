// https://www.acmicpc.net/problem/10039
// 2022-03-08 19:05:46 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int sum=0;
    for(int i=0; i<5; i++)
    {
        int a; scanf("%d", &a);
        if(a<40) a=40;
        sum+=a;
    }
    printf("%d", sum/5);
}

/*
    
*/