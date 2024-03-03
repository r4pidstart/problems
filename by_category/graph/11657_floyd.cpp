// https://www.acmicpc.net/problem/11657
// 2024-03-03 22:47:09
#include"bits/stdc++.h"
using namespace std;

class Floyd
{
    // adjacent matrix 1~n, O(V^3)
    public:
        vector<vector<long> > dist;
        Floyd(const vector<vector<long> >& graph)
        {
            dist=graph;
            for(int k=1; k<dist.size(); k++)
                for(int i=1; i<dist.size(); i++)
                    for(int j=1; j<dist.size(); j++)
                        if(dist[i][k]!=LONG_MAX/2 and dist[k][j]!=LONG_MAX/2)
                            dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
        }
};

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<long> > table(n+1, vector<long>(n+1, LONG_MAX/2));
    for(int i=1; i<=n; i++)
        table[i][i]=0;
    
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        table[a][b]=min(table[a][b], long(c));
    }

    Floyd first(table);

    // 1번 도시에서 출발해 어떤 도시로 가는 과정에서 시간을 무한히 오래 전으로 되돌릴 수 있다면 첫째 줄에 -1을 출력한다.
    // -> 1번 도시에서 도달 가능한 정점 중 사이클이 있다면?

    for(int i=1; i<=n; i++)
        if(first.dist[1][i]!=LONG_MAX/2 and first.dist[i][i]<0)
            return !printf("-1");

#ifdef LOCAL
    printf("\n");
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            printf("%2d ", first.dist[i][j]);
        printf("\n");
    }
#endif
    
    for(int i=2; i<=n; i++)
        printf("%ld\n", first.dist[1][i]==LONG_MAX/2 ? -1:first.dist[1][i]);
}

/*
    
*/