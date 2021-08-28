// https://www.acmicpc.net/problem/2563
// 2021-08-29 01:12:35 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<vector<int> > paper(101, vector<int>(101, 0));
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int x,y; scanf("%d%d", &x,&y);
        for(int i=1; i<=10; i++)
            for(int j=1; j<=10; j++)
                paper[x+i][y+j]++;
    }
    int ans=0;
    for(int i=1; i<=100; i++)
        for(int j=1; j<=100; j++)
            if(paper[i][j]) ans++;
    printf("%d", ans);
}

/*
      
*/