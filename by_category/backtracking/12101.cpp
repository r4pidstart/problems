// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int btrk(int n, int k, stack<int> &s)
{
    static int cnt=0;
    if(n<0)
        return 0;
    else if(n==0)
        return ++cnt==k;
    
    for(int i=1; i<=3; i++)
        if(btrk(n-i, k, s))
        {
            s.push(i);
            return 1;
        }
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &n, &k);
    stack<int> s;
    btrk(n, k, s);
    
    if(s.size())
        printf("%d", s.top()), s.pop();
    else
        printf("-1");
    while(s.size())
        printf("+%d", s.top()), s.pop();
}

/*
    
*/