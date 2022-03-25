// https://www.acmicpc.net/problem/10448
// 2022-03-26 07:10:46 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> table(1001);
    for(int i=1; i<=100; i++)
        for(int j=1; j<=100; j++)
            for(int k=1; k<=100; k++)
            {
                int tmp = i*(i+1)/2 + j*(j+1)/2 + k*(k+1)/2;
                if(tmp <= 1000) table[tmp]=1;
            }
    while(n--)
    {
        int a; scanf("%d", &a);
        printf("%d\n", table[a]);
    }
}

/*
    
*/