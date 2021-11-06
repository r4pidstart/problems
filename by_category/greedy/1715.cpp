// https://www.acmicpc.net/problem/1715
// 2021-11-07 01:11:12 28ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(int i=0; i<n; i++) pq.push(arr[i]);

    long long ans=0;
    while(pq.size()!=1)
    {
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();

        ans+=a+b;
        pq.push(a+b);
    }
    printf("%lld", ans);
}

/*
    
*/