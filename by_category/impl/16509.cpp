// https://www.acmicpc.net/problem/16509
// 2022-06-10 03:16:40 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d);
    queue<pair<pair<int,int>, int> > q;
    q.push({{a, b}, 0});

    int way[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<int> > visited(10, vector<int>(9));
    while(q.size())
    {
        int x=q.front().first.first, y=q.front().first.second, cnt=q.front().second;
        q.pop();

        if(x == c and y == d)
            return !printf("%d", cnt);
        
        if(visited[x][y]) continue;
        else visited[x][y]++;
        
        for(int i=0; i<4; i++)
        {
            int sx=x+way[i][0], sy=y+way[i][1];
            if(!(0<=sx and sx<10 and 0<=sy and sy<9)) continue;
            if(sx == c and sy == d) continue;

            int flag1=0;
            if(!way[i][0])
                swap(way[i][0], way[i][1]), swap(sx, sy), flag1++;

            for(int j=-1; j<2; j++)
            {
                if(!j) continue;

                int nx=sx, ny=sy, flag2=0;
                nx+=way[i][0], ny+=j;

                if(flag1) swap(nx, ny);
                if(!(0<=nx and nx<10 and 0<=ny and ny<9)) flag2++;
                if(nx == c and ny == d) flag2++;
                if(flag1) swap(nx, ny);

                nx+=way[i][0], ny+=j;

                if(flag1) swap(nx, ny);
                if(!(0<=nx and nx<10 and 0<=ny and ny<9)) flag2++;

                if(!flag2)
                    q.push({{nx, ny}, cnt+1});
            }
                    
            if(flag1)
                swap(way[i][0], way[i][1]);
        }
    }
    printf("-1");
}

/*
    
*/