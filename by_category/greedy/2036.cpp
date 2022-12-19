// https://www.acmicpc.net/problem/2036
// 2022-12-19 19:22:15
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);

    int zero_cnt=0;
    priority_queue<int> pq_pos;
    priority_queue<int, vector<int>, greater<> > pq_neg;
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d", &a);
        if(a==0) zero_cnt++;
        else if(a>0) pq_pos.push(a);
        else pq_neg.push(a);
    }

    long ans=0;
    while(pq_neg.size() and pq_neg.size() != 1)
    {
        int a=pq_neg.top();
        pq_neg.pop();
        int b=pq_neg.top();
        pq_neg.pop();
        ans+=(long)a*b;
    }
    
    if(pq_neg.size() and !zero_cnt)
        ans+=pq_neg.top();
    
    while(pq_pos.size() and pq_pos.size() != 1)
    {
        int a=pq_pos.top();
        pq_pos.pop();
        int b=pq_pos.top();
        pq_pos.pop();

        if(a==1 or b==1) ans+=a+b;
        else ans+=(long)a*b;
    }
    if(pq_pos.size())
        ans+=pq_pos.top();
    
    printf("%ld", ans);
}

/*
    
*/