// https://www.acmicpc.net/problem/1058
// 2022-05-15 00:00:15 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<char> > table(n, vector<char>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)  
            scanf(" %c", &table[i][j]);

    int ans=0;
    for(int i=0; i<n; i++)
    {
        // cnt
        vector<int> arr(n);
        queue<int> q;
        for(int j=0; j<n; j++)
            if(table[i][j]=='Y') arr[j]++, q.push(j);
        
        while(q.size())
        {
            int i=q.front(); q.pop();
            for(int j=0; j<n; j++)
                if(table[i][j]=='Y') arr[j]++;
        }
        
        int cnt=0;
        for(int j=0; j<n; j++)
            if(j!=i and arr[j]) cnt++;
        ans=max(ans, cnt);
    }
    printf("%d", ans);
}

/*
    
*/