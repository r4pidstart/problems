// https://www.acmicpc.net/problem/27450
// 2024-03-20 00:35:27
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n, k; scanf("%d%d", &n, &k);
    vector<int> origin(n);
    for(int i=0; i<n; i++)
        scanf("%d", &origin[i]);
    
    vector<int> target(n);
    for(int i=0; i<n; i++)
        scanf("%d", &target[i]);

    long sum=0, cnt=0, ans=0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    for(int i=0; i<n; i++)
    {
        sum-=cnt;
        assert(sum>=0);
        while(pq.size() and pq.top().first <= i)
        {
            auto [a, b]=pq.top();
            cnt-=b;
            assert(cnt>=0);
            pq.pop();
        }
        origin[i]+=sum;
        if(target[i]<=origin[i]) continue;

        long required=(target[i]-origin[i]+k-1)/k;
        pq.push({i+k, required});

        sum+=1L*required*k;
        cnt+=required;
        ans+=required;
    }
    printf("%ld", ans);
}

/*
    
*/