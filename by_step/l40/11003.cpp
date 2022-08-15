// https://www.acmicpc.net/problem/11003
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    cin.tie(NULL)->sync_with_stdio(false);
    int n,l; cin >> n >> l;
    vector<int> arr(n);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<> > pq;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    for(int i=0; i<n; i++)
    {
        pq.push({arr[i], i});
        while(pq.top().second <= i-l) pq.pop();
        cout << pq.top().first << ' ';
    }
}

/*
    
*/