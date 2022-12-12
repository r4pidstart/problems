// https://www.acmicpc.net/problem/23757
// 2022-12-13 01:31:07
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    priority_queue<int> pq;
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        pq.push(a);
    }

    for(int i=0; i<m; i++)
    {
        int a; scanf("%d", &a);
        if(pq.top() >= a)
        {
            int tmp=pq.top();
            pq.pop();
            pq.push(tmp-a);
        }
        else
            return !printf("0");
    }
    printf("1");
}

/*
    
*/