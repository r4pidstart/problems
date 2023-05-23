#pragma GCC optimize("O3")
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef struct pair
{   
    int first, second;
}pair;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    char table[n][m];
    int dist[n][m];
    memset(dist, 0, n*m*sizeof(int));
    pair q[n*m];
    int front=0, rear=0;

    int s1x=-1, s2x=-1, s1y, s2y;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            scanf(" %c", &table[i][j]);
            if(table[i][j]=='L')
            {
                if(s1x==-1) s1x=i, s1y=j;
                else s2x=i, s2y=j;
            }
            if(table[i][j] != 'X')
                q[rear++]=(pair){i, j}, dist[i][j]=1;
        }
    assert(s1x != -1 && s2x != -1);

    const int mov[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};
    while(front != rear)
    {
        int x=q[front].first, y=q[front].second;
        front++;

        for(int w=0; w<4; w++)
        {
            int nx=x+mov[w][0], ny=y+mov[w][1];
            if(0<=nx && nx<n && 0<=ny && ny<m)
            {
                if(!dist[nx][ny])
                {
                    dist[nx][ny]=dist[x][y]+1;
                    q[rear++]=(pair){nx, ny};
                }
            }
        }
    }

    int ans=1;
    front=0, rear=0;
    pair q2[n*m];
    int visited[n][m], visited2[n][m];
    memset(visited, 0, n*m*sizeof(int));
    memset(visited2, 0, n*m*sizeof(int));
    int front2=0, rear2=0;
    q2[rear2++]=(pair){s1x, s1y};
    visited[s1x][s1y]=1;
    while(front2!=rear2)
    {
        // pop and push all elements from q2 to q
        while(front2!=rear2)
        {
            visited[q2[front2].first][q2[front2].second]=1;
            q[rear++]=q2[front2++];
        }
        
        // bfs within dist[x][y]<=ans
        while(front!=rear)
        {
            int x=q[front].first, y=q[front].second;
            front++;

            for(int w=0; w<4; w++)
            {
                int nx=x+mov[w][0], ny=y+mov[w][1];
                if(0<=nx && nx<n && 0<=ny && ny<m && !visited[nx][ny])
                {
                    if(dist[nx][ny]<=ans)
                        q[rear++]=(pair){nx, ny}, visited[nx][ny]=1;
                    else if(dist[nx][ny]==ans+1 && !visited2[nx][ny]) // next candidates
                        q2[rear2++]=(pair){nx, ny}, visited2[nx][ny]=1;
                }
            }
        }
        // check whether two doves meet
        if(visited[s2x][s2y])
            return !printf("%d", ans-1);
        ans++;
    }
    return 1;
}