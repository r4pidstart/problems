// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > task(n+1, vector<int>());
    vector<int> indegree(n+1, 0), cost(n+1, 0);
    
    for(int i=1; i<=n; i++)
    {
        int b; scanf("%d%d", &cost[i],&b);
        for(int i=0; i<b; i++)
        {
            int c; scanf("%d", &c);
            task[c].push_back(i);
        }
    }

    queue<int> 
}

/*

*/