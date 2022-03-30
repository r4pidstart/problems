// https://www.acmicpc.net/problem/2161
// 2022-03-30 23:14:30 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    queue<int> q;
    for(int i=1; i<=n; i++)
        q.push(i);
    while(true)
    {
        printf("%d ", q.front());
        q.pop();
        if(!q.size()) break;
        q.push(q.front());
        q.pop();
    }
}

/*
    
*/