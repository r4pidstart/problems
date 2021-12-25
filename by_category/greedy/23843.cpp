// https://www.acmicpc.net/problem/23843
// 2021-12-26 04:05:33 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<m; i++)
        pq.push(0);

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    sort(arr.begin(), arr.end(), greater<int>());

    for(int i=0; i<n; i++)
    {
        int tmp=pq.top(); pq.pop();
        pq.push(tmp+arr[i]);
    }

    for(int i=0; i<m-1; i++)
        pq.pop();
    
    printf("%d", pq.top());
}

/*
    
*/