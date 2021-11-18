// https://www.acmicpc.net/problem/23349
// 2021-11-19 02:19:06 4ms
#include<bits/stdc++.h>
using namespace std;

struct Ans
{
    string place;
    int s,e;

    bool operator<(Ans& a)
    {
        if(place==a.place)
        {
            if(s==a.s)
                return e-s>a.e-a.s;
            else
                return s<a.s;
        }
        else
            return place<a.place;
    }
};

int main(void)
{
    map<int, string> m1;
    map<string, int> m2;
    set<string> se;
    int n; scanf("%d", &n);

    vector<vector<int> > arr(10, vector<int>(50002));
    int ansCandidate=0;
    for(int i=0; i<n; i++)
    {
        string name, place; int s,e;
        cin >> name >> place >> s >> e;
        if(se.find(name) != se.end()) continue;
        se.insert(name);
        
        int index;
        if(m2.find(place) != m2.end()) index=m2.find(place)->second;
        else m1[m1.size()]=place, index=m2[place]=m1.size()-1;

        for(int j=s; j<e; j++) 
        {
            arr[index][j]+=1;
            ansCandidate=max(ansCandidate, arr[index][j]);
        }
    }

    vector<Ans> ans;
    for(int i=0; i<10; i++)
    {
        int s=-1;
        for(int j=0; j<50002; j++)
        {
            if(s==-1 and ansCandidate==arr[i][j])
            {
                s=j;
            }
            if(s!=-1 and ansCandidate!=arr[i][j])
            {
                ans.push_back({m1[i], s, j});
                s=-1;
            } 
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans[0].place << ' ' << ans[0].s << ' ' << ans[0].e;
}

/*
    
*/