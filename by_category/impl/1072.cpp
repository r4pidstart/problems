// https://www.acmicpc.net/problem/1072
// 2022-03-31 00:18:12 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long x, y;
    scanf("%d%d", &x, &y);
    long long s=1, e=1e16, ans=1e10;
    while(s <= e)
    {
        long long mid=(s+e)/2;
        if(100*(mid + y)/(mid + x) > 100*y/x)
        {
            ans=mid;
            e=mid-1;
        }
        else
            s=mid+1;
    }
    printf("%d", ans);
}

/*
    
*/