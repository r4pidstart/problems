// https://www.acmicpc.net/problem/14720
// 2021-12-01 00:47:54 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    int ans=0, target=0;
    while(n--)
    {
        int tmp; scanf("%d", &tmp);
        if(tmp==target)
        {
            target=(target+1)%3;
            ans++;
        }
    }
    printf("%d", ans);
}

/*
    
*/