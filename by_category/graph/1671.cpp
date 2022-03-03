// https://www.acmicpc.net/problem/1671
// 2022-03-04 03:33:41 0ms
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
    int n; scanf("%d", &n);
    struct stats
    {
        int a,b,c;
        bool operator<(const stats& a) const
        {
            return this->a<=a.a and b<=a.b and c<=a.c;
        }
        bool operator==(const stats& a) const
        {
            return this->a==a.a and b==a.b and c==a.c;
        }
    };
    vector<stats> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d%d", &arr[i].a, &arr[i].b, &arr[i].c);
    
    bipartite_matching bi(n*2, n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(arr[i] < arr[j]) // j가 i를 먹을 수 있다면.
            {
                if(arr[i]==arr[j] and i<=j) continue; // 서로 먹히는 예외처리
                bi.add_edge(j*2+1, i);
                bi.add_edge(j*2, i);
            }
        }
    
    printf("%d", n-bi.find_match());
}

/*
    
*/