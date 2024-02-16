// https://www.acmicpc.net/problem/3657
// 2024-02-15 22:06:46
#include"bits/stdc++.h"
using namespace std;

inline double get_dist(const pair<long, long>& a, const pair<long, long>& b)
{
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
} 

int main(void)
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--)
    {
        int n,m; cin >> n >> m;
        vector<pair<long, long> > loc(n);
        vector<string> int_to_name(n);
        map<string, int> name_to_int;
        for(int i=0; i<n; i++)
        {
            string s;
            long a, b;
            cin >> s >> a >> b;
            name_to_int[s]=name_to_int.size();
            int_to_name[name_to_int[s]]=s;
            loc[name_to_int[s]]={a,b};
        }

        vector<vector<double> > graph(n, vector<double>(n, DBL_MAX/2));
        for(int i=0; i<n; i++)
            graph[i][i]=0;
        
        vector<int> shooted(n);
        for(int i=0; i<m; i++)
        {
            string a,b,c,trash;
            cin >> a >> trash >> b >> trash >> trash >> c;

            shooted[name_to_int[b]]=shooted[name_to_int[c]]=1;

            graph[name_to_int[b]][name_to_int[c]]=min(graph[name_to_int[b]][name_to_int[c]],
                get_dist(loc[name_to_int[c]], loc[name_to_int[a]])-get_dist(loc[name_to_int[b]], loc[name_to_int[a]]));
        }

        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    graph[i][j]=min(graph[i][j], graph[i][k]+graph[k][j]);

        int flag=0;
        for(int i=0; i<n; i++)
            if(graph[i][i]<0) // cycle 
                flag=1;
        
        if(flag)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        vector<string> ans;
        int cnt=accumulate(shooted.begin(), shooted.end(), 0);
        for(int i=0; !flag and i<cnt; i++)
        {
            vector<int> cand;
            for(int i=0; i<n; i++)
            {
                if(shooted[i])
                {
                    int flag=0;
                    for(int j=0; j<n; j++)
                        if(shooted[j] and graph[i][j]>0)
                            flag=1;
                    if(!flag)
                        cand.push_back(i);
                }
            }

            if(cand.size() != 1)
            {
                cout << "UNKNOWN\n";
                flag=1;
            }
            else
                ans.push_back(int_to_name[cand.front()]), shooted[cand.front()]=0;
        }
        
        if(flag)
            continue;

        for(string& s : ans)
            cout << s << ' ';
        cout << '\n';
    }
}

/*
    
*/