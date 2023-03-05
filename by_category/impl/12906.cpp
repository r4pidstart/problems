// https://www.acmicpc.net/problem/12906
// 2023-03-05 18:50:47
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    vector<vector<char> > arr(3);
    for(int i=0; i<3; i++)
    {
        int a; scanf("%d", &a);
        while(a--)
        {
            char c; scanf(" %c", &c);
            arr[i].push_back(c);
        }
    }

    set<vector<vector<char> > > visited;
    queue<pair<vector<vector<char> >, int> > q;
    q.push({arr, 0});
    visited.insert(arr);
    while(q.size())
    {
        auto [now, cnt]=q.front();
        q.pop();
        for(int i=0; i<3; i++)
        {
            for(char c : now[i])
                if(c!='A'+i) goto flag;
        }
        return !printf("%d", cnt);

        flag:
        for(int i=0; i<3; i++)
            if(now[i].size())
            {
                int tmp=now[i].back();
                now[i].pop_back();

                now[(i+1)%3].push_back(tmp);
                if(visited.find(now) == visited.end())
                    q.push({now, cnt+1}), visited.insert(now);
                now[(i+1)%3].pop_back();

                now[(i+2)%3].push_back(tmp);
                if(visited.find(now) == visited.end())
                    q.push({now, cnt+1}), visited.insert(now);
                now[(i+2)%3].pop_back();

                now[i].push_back(tmp);
            }
    }
}

/*
    
*/