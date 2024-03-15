// https://www.acmicpc.net/problem/14588
// 2024-03-13 19:34:57
#include"bits/stdc++.h"
using namespace std;

int solution(int a, int b, const vector<pair<int,int> >& arr)
{
    queue<int> q;
    q.push(a);
    vector<int> dist(arr.size(), INT32_MAX/2);
    dist[a]=0;

    while(q.size())
    {
        int now=q.front();
        q.pop();

        int ns=arr[now].first, ne=arr[now].second;
        for(int i=0; i<arr.size(); i++)
        {
            int s=arr[i].first, e=arr[i].second;
            if(!(e < ns) and !(ne < s))
                if(dist[i] > dist[now]+1)
                    dist[i]=dist[now]+1, q.push(i);
        }
    }
    return dist[b];
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    int q; scanf("%d", &q);
    while(q--)
    {
        int a,b; scanf("%d%d", &a, &b);
        int ans=solution(a-1, b-1, arr);
        printf("%d\n", ans==INT32_MAX/2 ? -1:ans);
    }
}

/*
    
*/