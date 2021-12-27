// https://www.acmicpc.net/problem/23845
// 2021-12-27 21:59:34 36ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> size(100002,0);
    for(int i=0; i<n; i++)
    {
        int tmp; scanf("%d", &tmp);
        size[tmp]++;
    }

    long long ans=0, prev=0;
    priority_queue<int> pq;
    for(long long i=0; i<100002; i++)
    {
        for(int j=0; j<size[i]-prev; j++)
            pq.push(i);
        for(int j=0; j<prev-size[i]; j++)
        {
            ans+=((i-1)*(i-pq.top()));
            pq.pop();
        }
        prev=size[i];
    }

    printf("%lld", ans);
}

/*
    
*/