// https://www.acmicpc.net/problem/10825
// 2022-02-03 00:07:11 60ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(NULL)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<pair<int, int>, pair<int, string> > > arr;
    for(int i=0; i<n; i++)
    {
        string a; int b,c,d;
        cin >> a >> b >> c >> d;
        arr.push_back({{-b, c}, {-d, a}});
    }
    sort(arr.begin(), arr.end());
    for(auto it : arr)
        cout << it.second.second << '\n';
}

/*
    
*/