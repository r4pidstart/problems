// https://www.acmicpc.net/problem/11014 , 1014
// 2022-03-06 03:05:31 52ms
#include<bits/stdc++.h>
using namespace std;

class bipartite_matching
{
    // O(VE)
    private:
        vector<vector<int> > graph;
        vector<int> btoa, visited;
        int visit_cnt=0;
        bool make_match(int now)
        {
            visited[now]=visit_cnt;
            for(int next : graph[now])
                if(btoa[next] == -1 or (visited[btoa[next]] != visit_cnt and make_match(btoa[next])))
                {
                    btoa[next]=now;
                    return 1;
                }
            return 0;
        }
    public: 
        bipartite_matching(int sizeA, int sizeB)
        {
            graph.assign(sizeA, vector<int>());
            btoa.assign(sizeB, -1);
            visited.assign(sizeA, 0);
        }
        inline void add_edge(int fromA, int toB)
        {
            graph[fromA].push_back(toB);
        }
        int find_match(void) 
        {
            int match=0;
            for(int i=0; i<graph.size(); i++)
            {
                visit_cnt++;
                if(make_match(i)) match++;
            }
            return match;
        }
};

int main(void)
{
    int t; scanf("%d", &t);
    const int cheat_possible[4][2]={{-1, -1}, {0, -1}, {0, +1}, {-1, +1}};
    while(t--)
    {
        int n,m; scanf("%d%d", &n, &m);
        vector<vector<char> > table(n, vector<char>(m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                scanf(" %c", &table[i][j]);

        bipartite_matching bi(n*m, n*m);

        int total_seats=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(table[i][j] == 'x') continue;

                total_seats++;
                for(int k=0; k<4; k++)
                {
                    int nx=i+cheat_possible[k][0], ny=j+cheat_possible[k][1];
                    if(0<=nx and nx<n and 0<=ny and ny<m and table[nx][ny]=='.')
                    {
                        // 앉은 자리 -> 컨닝 가능한 자리
                        if(j&1) bi.add_edge(i*m + j, nx*m + ny);
                        else bi.add_edge(nx*m + ny, i*m + j);
                    }
                }
                
            }
        printf("%d\n", total_seats-bi.find_match());
    }
}

/*
    각 자리별로 컨닝할 수 있는 모든 자리를 간선으로 만들면, 그 간선들 중 한 쪽에만 사람을 둘 수 있다.
    그렇다면, 자리들을 이분그래프로 표현하여, 최소 버텍스 커버를 찾는다면,
    모든 자리 - 최소 버텍스 커버가 교실에 배치할 수 있는 최대 학생 수가 될 것이다.

    그럼, 어떻게 자리들을 이분그래프로 표현하는가?
    문제의 조건을 보면, 컨닝할 수 있는 자리는 왼쪽 상단, 오른쪽 상단, 그리고 왼쪽과 오른쪽 인 것을 알 수 있다.
    즉, 같은 줄에 있는 자리는 컨닝할 수 없다는 것이다.
    이 조건을 이용하여, 모든 자리를 짝수열과 홀수열로 나눌 수 있다.
*/