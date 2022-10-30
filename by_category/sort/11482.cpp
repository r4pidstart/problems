// https://www.acmicpc.net/problem/11482
// 2022-10-30 21:01:21
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    cin.ignore();
    set<string> usrs;
    map<string, pair<int, set<string> > > used;

    while(n--)
    {
        string s;
        getline(cin, s);
        string name, word;
        stringstream ss(s);
        ss >> name;
        usrs.insert(name);

        while(ss >> word)
        {
            used[word].second.insert(name);
            used[word].first--;
        }
    }

    vector<pair<int, string> > arr;
    for(auto it : used)
    {
        if(it.second.second.size() == usrs.size())
            arr.push_back({it.second.first, it.first});
    }
    sort(arr.begin(), arr.end());
    for(auto it : arr)
        cout << it.second << '\n';
    if(arr.size() == 0)
        cout << "ALL CLEAR";
}

/*
    
*/