// https://www.acmicpc.net/problem/2633
// 2022-03-25 05:01:50 32ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int sx,sy; scanf("%d%d", &sx, &sy);
    int ex,ey; scanf("%d%d", &ex, &ey);
    sx=sx*2-1, sy=sy*2-1, ex=ex*2-1, ey=ey*2-1;

    vector<vector<int> > tmptable(220, vector<int>(220,0)), table(220, vector<int>(220,0));
    // table[sx][sy]=3, table[ex][ey]=4;
    int n; scanf("%d", &n);
    while(n--)
    {
        int ax,ay, bx,by, cx,cy, dx,dy;
        scanf("%d%d %d%d %d%d %d%d", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
        // find dir
        ax=ax*2, bx=bx*2, cx=cx*2, dx=dx*2, ay=ay*2, by=by*2, cy=cy*2, dy=dy*2;
        int up=max({ay, by, cy, dy})-2;
        int down=min({ay, by, cy, dy});
        int left=min({ax, bx, cx, dx});
        int right=max({ax, bx, cx, dx})-2;

        for(int j=down; j<=up; j++)
            for(int i=left; i<=right; i++)
                tmptable[i][j]=1;

        if(ax==bx and by==cy)
        {
            // ㅁ 
            // ㅁㅁ
            if(dx < cx)
            {
                for(int i=dx-1; i<=right; i++)
                    for(int j=dy-1; j<=up; j++)
                        tmptable[i][j]=0;
            }
            // ㅁㅁ 
            //  ㅁ
            else
            {
                for(int i=cx; i<=dx-1; i++)
                    for(int j=down; j<=dy-1; j++)
                        tmptable[i][j]=0;
            }
        }
        else
        {
            //  ㅁ
            // ㅁㅁ
            if(dx < cx)
            {
                for(int i=left; i<=dx-1; i++)
                    for(int j=dy-1; j<=up; j++)
                        tmptable[i][j]=0;
            }
            // ㅁㅁ
            // ㅁ
            else
            {
                for(int i=dx-1; i<=right; i++)
                    for(int j=down; j<=dy-1; j++)
                        tmptable[i][j]=0;
            }
        }
        
        for(int j=down; j<=up; j++)
            for(int i=left; i<=right; i++)
                if(tmptable[i][j]) table[i][j]=1;
    }

    // for(int i=0; i<100; i++)
    // {
    //     for(int j=0; j<100; j++)
    //         printf("%d", table[i][j]);
    //     printf("\n");
    // }
    // printf("\n");

    vector<vector<vector<int> > > dist(220, vector<vector<int> >(220, vector<int>(5, INT32_MAX/2)));
    const int mov[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    struct status
    {
        int x, y, dir, cnt;
    };

    struct comp
    {
        bool operator()(const status& a, const status& b) const
        {
            return a.cnt > b.cnt;
        }
    };
    priority_queue<status, vector<status>, comp> pq;
    pq.push({sx, sy, 4, -1});
    dist[sx][sy][4]=-1;
    while(!pq.empty())
    {
        auto now=pq.top(); pq.pop();
        if(dist[now.x][now.y][now.dir] < now.cnt) continue;
        for(int m=0; m<4; m++)
        {
            int nx=now.x+mov[m][0], ny=now.y+mov[m][1];
            if(0<nx and nx<200 and 0<ny and ny<200 and !table[nx][ny])
            {
                int next_cost=now.cnt + (m!=now.dir);
                if(next_cost < dist[nx][ny][m])
                {
                    dist[nx][ny][m]=next_cost;
                    pq.push({nx, ny, m, next_cost});
                }
            }
        }
    }

    printf("%d", *min_element(dist[ex][ey].begin(), dist[ex][ey].end()));

}

/*
    --------
    ㅣㅁㅣㅁㅣ
    --------

    OO
     O

    OO
    O

    O
    OO

     O
    OO
*/