// https://www.acmicpc.net/problem/21237
// 2021-10-29 03:32:02 12ms
#include<bits/stdc++.h>
using namespace std;

const int way[4][2]={{0,1}, {1,0}, {-1,0}, {0,-1}};

int main(void)
{
    int n; scanf("%d", &n);
    while(n--)
    {
        vector<vector<int> > table(250, vector<int>(250));
        string s; cin >> s;
        char firstD=s[0];
        
        int curX=125, curY=125;
        table[curX][curY]=1;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='N')
            {
                table[curX][curY-1]=1;
                table[curX][curY-2]=1;
                curY-=2;
            }
            else if(s[i]=='E')
            {
                table[curX+1][curY]=1;
                table[curX+2][curY]=1;
                curX+=2;
            }
            else if(s[i]=='S')
            {
                table[curX][curY+1]=1;
                table[curX][curY+2]=1;
                curY+=2;
            }
            else if(s[i]=='W')
            {
                table[curX-1][curY]=1;
                table[curX-2][curY]=1;
                curX-=2;
            }
        }

        queue<pair<int,int> > q;
        int area=0;

        if(firstD=='E')
            q.push({126, 126}); 
        else if (firstD=='W')
            q.push({124, 124});
        else if(firstD=='N')
            q.push({126, 124});
        else if(firstD=='S')
            q.push({124, 126});

        while(!q.empty())
        {
            auto now=q.front(); 
            q.pop();
            if(table[now.first][now.second]) continue;
            area++, table[now.first][now.second]=2;

            for(int i=0; i<4; i++)
            {
                int nx=now.first+way[i][0], ny=now.second+way[i][1];
                if(0<=nx and nx<250 and 0<=ny and ny<250 and !table[nx][ny])
                    q.push({nx, ny});
            }
        }

        if(area < 10000) printf("CW\n");
        else printf("CCW\n");
    }
}

/*
    
*/