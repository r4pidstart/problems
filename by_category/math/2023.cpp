// https://www.acmicpc.net/problem/2023
// 2021-12-12 02:31:48 0ms
#include<bits/stdc++.h>
using namespace std;

inline int is_prime(int n)
{
    for(int i=2; i*i<=n; i++)
        if(!(n%i)) return 0;
    return 1;
}

int main(void)
{
	int n; scanf("%d", &n);

    queue<int> q;
    q.push(2), q.push(3), q.push(5), q.push(7);
    while(!q.empty()) // bfs
    {
        int now=q.front(); q.pop();
        if(now>=pow(10, n-1)) 
        {
            printf("%d\n", now);
            continue;
        }

        for(int i=0; i<10; i++)
            if(is_prime(now*10+i)) q.push(now*10+i);
    }
}

/*
	
*/