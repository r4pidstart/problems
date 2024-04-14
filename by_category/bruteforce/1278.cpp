// https://www.acmicpc.net/problem/1278
// 2024-04-10 01:08:48
#include"bits/stdc++.h"
using namespace std;

int dfs(bitset<20> now, int n, vector<int>& used)
{
    for(int i=0; i<n; i++)
    {
        if(!now[i] and !used[bitset<20>(now).set(i).to_ulong()])
        {
            now.set(i);
            used[now.to_ulong()]=1;
            printf("%d\n", i+1);
            return dfs(now, n, used);
        }
        if(now[i] and !used[bitset<20>(now).reset(i).to_ulong()])
        {
            now.reset(i);
            used[now.to_ulong()]=1;
            printf("%d\n", i+1);
            return dfs(now, n, used);
        }
    }
    return 0;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> used((1<<n)+1);
    used[0]=1;
    printf("%d\n", (1<<n)-1);
    dfs(0, n, used);
    printf("%d", n);
}

/*
    
*/