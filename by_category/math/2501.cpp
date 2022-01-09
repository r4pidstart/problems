// https://www.acmicpc.net/problem/2501
// 2022-01-10 01:16:35 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,k, cnt=0; scanf("%d%d", &n,&k);
    for(int i=1; i<=n; i++)
    {
        if(n%i == 0)
        {
            cnt++;
            if(cnt==k) return !printf("%d", i);
        }
    }
    printf("0");
}

/*
    
*/