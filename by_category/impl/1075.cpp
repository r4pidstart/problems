// https://www.acmicpc.net/problem/1075
// 2022-01-14 03:35:58 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,f; scanf("%d%d", &n,&f);
    int target=n-n%100;
    for(int i=0; i<100; i++)
        if((target+i)%f==0) return !printf("%02d", i);
}

/*
    
*/