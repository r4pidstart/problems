// https://www.acmicpc.net/problem/
// DICTIONARY
#include"bits/stdc++.h"
using namespace std;

int topological_something(int idx, vector<string>& arr, vector<set<int> >& graph, vector<int>& indegree)
{
    vector<char> prev_lst;
    prev_lst.push_back(arr[0][idx]);
    for(int i=0; i<arr.size(); i++)
        if(prev_lst.back() != arr[i][idx])
        {
            for(int j=0; j<prev_lst.size(); j++)
            {
                if(graph[prev_lst[j]-'a'].find(arr[i][idx]-'a') == graph[prev_lst[j]-'a'].end())
                    indegree[arr[i][idx]-'a']++, graph[prev_lst[j]-'a'].insert(arr[i][idx]-'a');
            }
            prev_lst.push_back(arr[i][idx]);
        }
 
    vector<vector<string> > bucket(26);
    for(int i=0; i<arr.size(); i++)
        if(arr[i].size()==idx) continue;
        else bucket[arr[i][idx]-'a'].push_back(arr[i]);
    
    for(int i=0; i<26; i++)
        if(bucket[i].size())
            topological_something(idx+1, bucket[i], graph, indegree);

    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<string> arr(n);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        
        vector<set<int> > graph(26);
        vector<int> indegree(26);

        topological_something(0, arr, graph, indegree);

        string char_seq=string();
        queue<char> q;
        vector<int> visited(26);
        for(int i=0; i<26; i++)
            if(!indegree[i])
                visited[i]=1, q.push(i);

        while(q.size())
        {
            int now=q.front(); q.pop();

            char_seq.push_back(now+'a');
            for(auto it=graph[now].begin(); it!=graph[now].end(); it++)
            {
                indegree[*it]--;
                if(!indegree[*it])
                    visited[*it]=1, q.push(*it);
            }
        }
        if(char_seq.size() != 26)
            printf("INVALID HYPOTHESIS\n");
        else
            printf("%s\n", char_seq.c_str());
    }
}

/*
    
*/