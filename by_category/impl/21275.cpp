// https://www.acmicpc.net/problem/21275
// 2022-03-05 07:23:33 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string a,b; cin >> a >> b;
    // str to int
    vector<vector<long long> > arr(2, vector<long long>(37, -1));
    function<long long(string, int)> to_int = [](string a, int base)->long long
    {
        __int128_t ret = 0;
        for(char c : a)
        {
            if(base <= (c>='a' ? c-'a'+10 : c-'0') or ret >= LLONG_MAX) return -1;
            ret = ret*base + (c>='a' ? c-'a'+10 : c-'0');
        }
        return ret >= LLONG_MAX ? -1 : ret;
    };

    for(int i=2; i<=36; i++)
        arr[0][i]=to_int(a, i), arr[1][i]=to_int(b, i);

    vector<pair<long long, pair<int, int> > > ans;
    for(int i=2; i<=36; i++)
        for(int j=2; j<=36; j++)
            if(i != j and arr[0][i] != -1 and arr[0][i]==arr[1][j])
                ans.push_back({arr[0][i], {i,j}});
    
    if(ans.size())
    {
        if(ans.size() > 1)
            printf("Multiple");
        else
            printf("%lld %d %d", ans[0].first, ans[0].second.first, ans[0].second.second);
    }
    else
        printf("Impossible");
}

/*
    
*/