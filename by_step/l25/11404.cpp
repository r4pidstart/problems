// https://www.acmicpc.net/problem/11404
// 2021-04-18 22:24:51 36ms
#include<iostream>
#include<vector>
#define INF 0x6FFFFFF
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;

vector<vector<int> > dist (101, vector<int> (101, INF));

int main(void)
{
    int n, m; scanf("%d%d", &n, &m);
    
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        if(dist[a][b]>c)
            dist[a][b]=c;
    }
    for(int i=0; i<=n; i++)
        dist[i][i]=0;

    for(int via=1; via<=n; via++)
        for(int start=1; start<=n; start++)
            for(int end=1; end<=n; end++)
                dist[start][end]=min(dist[start][via]+dist[via][end], dist[start][end]);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            printf("%d ", dist[i][j]==INF ? 0:dist[i][j]);
        }
        printf("\n");
    }    
    return 0;
}