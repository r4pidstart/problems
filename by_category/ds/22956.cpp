// https://www.acmicpc.net/problem/22956
// 2023-11-25 02:56:35
#include"bits/stdc++.h"
using namespace std;

class Dsu
{
    private:
        vector<int> parent;
    public:
        Dsu(int size)
        {
            parent.assign(size, -1);
        }
        int find(int i)
        {
            if(parent[i]<0) return i;
            else return parent[i]=find(parent[i]);
        }
        int merge(int a, int b)
        {
            a=find(a), b=find(b);
            if(a==b) return 1;

            // if(parent[a]<parent[b]) swap(a,b);
            parent[a]+=parent[b];
            parent[b]=a;
            return 0;
        }
        int size(int i)
        {
            return -parent[find(i)];
        }
};

int main(void)
{
#ifdef LOCAL
#endif
    int n,m,q; scanf("%d%d%d", &n, &m, &q);
    vector<vector<int> > table(n, vector<int>(m)), rained(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &table[i][j]);
    
    Dsu dsu(n*m);
    // ans[set_idx]={height, q_num(last accessed), idx}
    map<int, tuple<int, int, int> > ans;
    for(int i=1; i<=q; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        a--, b--;

        if(ans.find(dsu.find(a*m+b)) == ans.end())
            ans[dsu.find(a*m+b)]={table[a][b]-c, i, a*m+b};

        if(!rained[a][b])
        {
            // check the sets adjecent
            const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
            for(int w=0; w<4; w++)
            {
                int nx=a+way[w][0], ny=b+way[w][1];
                if(0<=nx and nx<n and 0<=ny and ny<m and rained[nx][ny])
                {
                    int sa=dsu.find(a*m+b), sb=dsu.find(nx*m+ny);
                    if(dsu.size(sa) < dsu.size(sb))
                        swap(sa, sb);
                    dsu.merge(sa, sb);
                    ans[sa]=min(ans[sa], ans[sb]);
                    // ans.erase(sb);
                }
            }
        }

        rained[a][b]=i;
        table[a][b]-=c;

        int target=dsu.find(a*m+b);
        ans[target]=min(ans[target], {table[a][b], rained[a][b], a*m+b});
        auto [d, t, idx]=ans[target];
        printf("%d %d\n", idx/m+1, idx%m+1);
    }
}

/*
    
*/