// https://www.acmicpc.net/problem/2179
// 2022-07-13 23:48:49
#include"bits/stdc++.h"
using namespace std;

struct ahhhh
{
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const
    {
        return a.second < b.second;
    }
};

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<string, int> > arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i].first, arr[i].second=i;
    
    int val=-1;
    sort(arr.begin(), arr.end());

    map<string, set<pair<string, int>, ahhhh> > m;
    for(int i=0; i<arr.size()-1; i++)
    {
        int cnt=0;
        while(cnt < arr[i].first.length() and cnt < arr[i+1].first.length() 
            and arr[i].first[cnt] == arr[i+1].first[cnt]) cnt++;

        string common_string=arr[i].first.substr(0,cnt);
        m[common_string].insert(arr[i]);
        m[common_string].insert(arr[i+1]);
        val=max(val, cnt);
    }

    pair<string, int> ans1({"", INT32_MAX}), ans2({"", INT32_MAX});
    for(auto it : m)
        if(it.first.length() == val)
        {
            auto tmp1=it.second.begin(), tmp2=++it.second.begin();
            if(ans1.second > tmp1->second)
                ans1=*tmp1, ans2=*tmp2;
            else if(ans1.second == tmp1->second and ans2.second > tmp2->second)
                ans1=*tmp1, ans2=*tmp2;
        }

    if(ans1.second > ans2.second)
        swap(ans1, ans2);
    cout << ans1.first << '\n' << ans2.first;
}

/*
    
*/