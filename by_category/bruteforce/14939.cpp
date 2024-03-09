// https://www.acmicpc.net/problem/14939
// 2024-03-07 23:19:04
#include"bits/stdc++.h"
using namespace std;

int click(int i, int j, vector<vector<char> >& table)
{
    const int way[9][2]={{0,0}, {0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    for(int w=0; w<5; w++)
    {
        int x=i+way[w][0], y=j+way[w][1];
        if(0<=x and x<10 and 0<=y and y<10)
            table[x][y]^=1;
    }
    return 0;
}

int solution(int now, int mask, vector<vector<char> >& table)
{
    if(now==10)
    {
        return accumulate(table[9].begin(), table[9].end(), 0)==0 ? 0:INT32_MAX/2;
    }
    else if(!now)
    {
        int cnt=0;
        for(int i=0; i<10; i++)
            if(mask & 1<<i)
                cnt++, click(0, i, table);

        return cnt+solution(now+1, mask, table);
    }
    else
    {
        int cnt=0;
        for(int i=0; i<10; i++)
            if(table[now-1][i])
                cnt++, click(now, i, table);
        
        return cnt+solution(now+1, mask, table);
    }
}

int main(void)
{
    vector<vector<char> > table(10, vector<char>(10));
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            scanf(" %c", &table[i][j]);

    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            table[i][j]=table[i][j]=='O';
    
    int ans=INT32_MAX/2;
    for(int i=0; i<(1<<10); i++)
    {
        auto tmp=table;
        ans=min(ans, solution(0, i, tmp));
    }
    
    printf("%d", ans==INT32_MAX/2 ? -1:ans);
}

/*
    
*/