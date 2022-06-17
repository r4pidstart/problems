// https://www.acmicpc.net/problem/15828
// 2022-06-17 03:01:15 40ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    queue<int> q;

    int a; scanf("%d", &a);
    while(a != -1)
    {
        if(a==0)
            q.pop();
        else if(q.size() < n)
            q.push(a);
        scanf("%d", &a);
    }

    if(!q.size()) printf("empty");
    while(q.size())
        printf("%d ", q.front()), q.pop();
}

/*
    
*/