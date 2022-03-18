// https://www.acmicpc.net/problem/2653
// 2022-03-19 01:11:09 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > adj(n, vector<int>(n,0));

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &adj[i][j]);
    
    vector<vector<int> > ans;
    vector<int> visited(n);
    for(int i=0; i<n; i++)
    {
        if(!visited[i]) 
        {
            vector<int> friends;
            for(int j=0; j<n; j++)
                if(adj[i][j] == 0) friends.push_back(j), visited[j]=1; // 친구 목록 기록

            // 각 친구에 대해서 adj[i]와 비교
            for(int target : friends)
                if(adj[i] != adj[target])
                    return !printf("0");
            
            if(friends.size() < 2) // 어떤 한 사람을 좋아하는 사람이 아무도 없다면 이 집단은 안정된 집단이 아니다.
                return !printf("0"); 
            ans.push_back(friends);
        }
    }

    printf("%d\n", ans.size());
    for(auto v : ans)
    {
        for(int i : v)
            printf("%d ", i+1);
        printf("\n");
    }
}

/*
    
*/