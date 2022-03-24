// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int ans=0;
    int n; scanf("%d", &n);
    while(n--)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        // 3개 동일
        if (a==b and b==c)
            ans=max(ans, a*1000+10000);
        else if(a==b or b==c or a==c)
        {
            int same;
            if(a==b) same = a;
            if(b==c) same = b;
            if(a==c) same = a;
            ans=max(ans, same*100+1000);
        }
        else
            ans=max(ans, max({a,b,c})*100);
    }
    printf("%d", ans);
}

/*
    
*/