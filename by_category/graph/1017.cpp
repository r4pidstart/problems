// https://www.acmicpc.net/problem/1017
// 2022-03-04 02:11:47 0ms
#include<bits/stdc++.h>
using namespace std;

class bipartite_matching
{
    // O(VE)
    public:
        int fixed;
        vector<vector<int> > graph;
        vector<int> btoa, visited;
        int visit_cnt=0;
        bool make_match(int now)
        {
            if(now == 0) return 0;
            visited[now]=visit_cnt;
            for(int next : graph[now])
            {
                if(next == fixed) continue;
                if(btoa[next] == -1 or (visited[btoa[next]] != visit_cnt and make_match(btoa[next])))
                {
                    btoa[next]=now;
                    return 1;
                }
            }
            return 0;
        } 
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
    vector<int> arr0, arr1;
    int flag=0;
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        if(!i) flag=a&1;
        if(flag) a&1 ? arr0.push_back(a):arr1.push_back(a);
        else a&1 ? arr1.push_back(a):arr0.push_back(a);
    }

    vector<int> prime_table(3000, 1);
    prime_table[1]=0;
    for(int i=2; i*i<3000; i++)
        for(int j=i+i; j<3000; j+=i)
            prime_table[j]=0;
    
    // 더해서 소수가 만들어지는 수들로 이분그래프를 만들자.
    bipartite_matching bi(arr0.size(), arr1.size());
    for(int i=0; i<arr0.size(); i++)
        for(int j=0; j<arr1.size(); j++)
            if(prime_table[arr0[i]+arr1[j]])
                bi.add_edge(i, j);

    // 첫 번째 수를 짝지어놓고, 나머지에 대해 이분매칭을 돌리자.
    vector<int> ans;
    for(int first_match : bi.graph[0])
    {
        bi.btoa.assign(arr1.size(), -1); // 초기화

        // 첫 번째 수와 짝짓기
        bi.btoa[first_match]=0;
        bi.fixed=first_match;

        if(bi.find_match() == n/2 -1) // 모든 수가 짝지어졌다면
            ans.push_back(arr1[first_match]);
    }

    sort(ans.begin(), ans.end());
    for(int i : ans)
        printf("%d ", i);
    if(ans.size() == 0)
        printf("-1");
}

/*
    
*/