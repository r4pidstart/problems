// https://www.acmicpc.net/problem/1956
// 2021-04-19 04:07:38 116ms
#include<iostream>
#include<vector>
#define INF 0x6FFFFFF
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;

vector<vector<int> > dist (401, vector<int> (401, INF));

int main(void)
{
    int v, e; scanf("%d%d", &v, &e);
    for(int i=0; i<e; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        dist[a][b]=c;
    }
    for(int i=1; i<=v; i++)
        dist[i][i]=0;
    
    for(int mid=1; mid<=v; mid++)
        for(int start=1; start<=v; start++)
            for(int end=1; end<=v; end++)
                dist[start][end]=min(dist[start][mid]+dist[mid][end], dist[start][end]);
    
    int optimal_route=INF;
    for(int i=1; i<=v; i++)
        for(int j=i+1; j<=v; j++)
            optimal_route=min(dist[i][j]+dist[j][i], optimal_route);

    printf("%d", optimal_route==INF ? -1:optimal_route);
    return 0;
}

//1956
