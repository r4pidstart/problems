// https://www.acmicpc.net/problem/11780
// 2021-05-01 19:39:45 44ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, m; scanf("%d%d", &n,&m);
    vector<vector<int> > dist(n+1, vector<int>(n+1, INT32_MAX/2)),
                         route(n+1, vector<int>(n+1, 0));


    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        dist[a][b]=min(c, dist[a][b]);
        route[a][b]=b;
    }

    for(int i=0; i<=n; i++)
        dist[i][i]=0;

    
    for(int i=1; i<=n; i++) // 경유
        for(int j=1; j<=n; j++) // 출발
            for(int k=1; k<=n; k++) // 도착
            {
                if(dist[j][k] > dist[j][i]+dist[i][k])
                {
                    dist[j][k]=dist[j][i]+dist[i][k];
                    route[j][k]=route[j][i];
                    // j->k로 가는데 i를 거쳐야 함.
                    // j->i로 가는 경로를 추가.
                }
            }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            printf("%d ", dist[i][j]==INT32_MAX/2 ? 0:dist[i][j]);
        printf("\n");
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(dist[i][j]==INT32_MAX/2 || dist[i][j]==0)
            // 갈 수 없거나, 정점을 거치지 않는다면
            {
                printf("0\n");
                continue;
            }
            vector<int> tmp_path;
            int pointer=i;
            while(pointer!=j)
            {
                tmp_path.push_back(pointer);
                pointer=route[pointer][j];
            }
            tmp_path.push_back(j);
            printf("%ld ", tmp_path.size());
            for(int point : tmp_path)
                printf("%d ", point);
            printf("\n");
        }
    }
}
