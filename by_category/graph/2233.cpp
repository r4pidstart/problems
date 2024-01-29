// https://www.acmicpc.net/problem/2233
// 2024-01-30 04:54:14
#include"bits/stdc++.h"
using namespace std;

int make_tree(const string& s, vector<vector<int> >& graph, vector<pair<int,int> >& arr)
{
    static int idx=0; // idx of s
    static int cnt=0; // cnt of vertex

    int now=cnt++;
    arr[now].first=idx+1;
    while(++idx < s.size() and s[idx]=='0') // new vertex
    {
        graph[now].push_back(cnt);
        make_tree(s, graph, arr);   
    }
    arr[now].second=idx+1;

    return 0;
}

int get_target(int now, const vector<vector<int> >& graph, int a, int b)
{
    if(now==a or now==b)
        return now;

    int cnt=0, ret=0;
    for(int next : graph[now])
    {
        int tmp=get_target(next, graph, a, b);
        if(tmp) ret=tmp, cnt++;
    }

    if(cnt==2)
        return now;
    return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    string s; cin >> s;
    int a,b; scanf("%d%d", &a, &b);

    vector<pair<int, int> > arr(n+1);
    vector<vector<int> > graph(n+1);
    make_tree(s, graph, arr);

    int t1,t2;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i].first==a or arr[i].second==a) t1=i;
        if(arr[i].first==b or arr[i].second==b) t2=i;
    }

    int target=get_target(0, graph, t1, t2);
    printf("%d %d", arr[target].first, arr[target].second);
}

/*
    
*/