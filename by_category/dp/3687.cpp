// https://www.acmicpc.net/problem/3687
// 2024-05-16 01:03:27
#include"bits/stdc++.h"
using namespace std;

const int req[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

auto operator<=>(const string& a, const string& b)
{
    if(a.size() != b.size())
        return (int)a.size()-(int)b.size();
    for(int i=0; i<a.size(); i++)
        if(a[i] != b[i])
            return a[i]-b[i];
    return 0;
}

pair<string, string> solution(int n, int digit)
{
    static vector<vector<string> > dp_min(101, vector<string>(51)), dp_max(101, vector<string>(51));
    if(dp_min[n][digit].size())
        return {dp_min[n][digit], dp_max[n][digit]};
    if(n==0)
        return {"", ""};

    string ret_min=string(100, '.'), ret_max="";
    // append one digit
    for(int i=!digit; i<10; i++)
    {
        if(n >= req[i])
        {
            string tmp1=to_string(i)+solution(n-req[i], digit+1).first;
            string tmp2=to_string(i)+solution(n-req[i], digit+1).second;
            if(tmp1 < ret_min)
                ret_min=tmp1;
            if(tmp2 > ret_max)
                ret_max=tmp2;
        }
    }
    
    return {dp_min[n][digit]=ret_min, dp_max[n][digit]=ret_max};
}

int main(void)
{
#ifdef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        auto [ans_min, ans_max]=solution(n, 0);
        cout << ans_min << ' ' << ans_max << '\n';
    }
}

/*
    
*/