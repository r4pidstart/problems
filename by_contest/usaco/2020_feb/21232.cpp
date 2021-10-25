// https://www.acmicpc.net/problem/21232
// 2021-10-26 02:23:28 240ms
#include<bits/stdc++.h>
using namespace std;

const int way[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
vector<vector<int> > table(3000, vector<int>(3000,0));
set<pair<int, int> > s;

void check(int x, int y, int c)
{
    if(c==0 and s.find({x,y}) != s.end()) 
    {
        s.erase({x,y});
        return;
    }

    int adjCnt=0;
    pair<int,int> cand;
    for(int m=0; m<4; m++)
    {
        int nx=x+way[m][0], ny=y+way[m][1];
        if(!table[nx][ny]) cand={nx,ny};
        else adjCnt++;
    }     
    if(adjCnt==3) 
    {
        s.insert(cand), table[cand.first][cand.second]++;
        check(cand.first, cand.second, 1);
    }

    for(int m=0; m<4; m++)
    {
        int nx=x+way[m][0], ny=y+way[m][1];
        adjCnt=0;
        if(table[nx][ny]) // !!
        {
            for(int i=0; i<4; i++)
            {
                int nnx=nx+way[i][0], nny=ny+way[i][1];
                if(!table[nnx][nny]) cand={nnx,nny};
                else adjCnt++;
            }
            if(adjCnt==3)
            {
                s.insert(cand), table[cand.first][cand.second]++;
                check(cand.first, cand.second, 1);
            }
        }
    }
}

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int x,y; scanf("%d%d", &x, &y);
        x+=1000, y+=1000;
        table[x][y]=1;

        check(x,y,0);
        printf("%d\n", (int)s.size());
    }
}

/*
    
*/