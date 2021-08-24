// https://www.acmicpc.net/problem/9507
// 2021-08-25 01:21:33 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<long long> pibo(70, 0);
    pibo[0]=1, pibo[1]=1, pibo[2]=2, pibo[3]=4;
    for(int i=4; i<=69; i++)
        pibo[i]=pibo[i-1]+pibo[i-2]+pibo[i-3]+pibo[i-4];
    
    int t; scanf("%d", &t);
    while(t--)
    {
        int a; scanf("%d", &a);
        printf("%lld\n", pibo[a]);
    }
}

/*

*/