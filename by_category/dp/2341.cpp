// https://www.acmicpc.net/problem/2341
// 2024-06-09 14:30:12
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

pair<int, string> solution(int idx, int prev, int len, int w, const vector<int>& arr)
{
    const int level[]={1, 86, 172, 256};
    const string code[]={"00", "01", "10", "11"};
    static vector dp(arr.size()+1, vector(5, vector(arr.size()*3+1, pair<int, string>(-1, ""))));

    if(idx==arr.size())
        return {0, ""};
    if(dp[idx][prev][len].first != -1)
        return dp[idx][prev][len];

    int ret_error=INT32_MAX/2;
    string ret_str="";
    for(int i=0; i<4; i++)
    {
        // idx번째를 i번째 코드로 치환했을 떄?
        if(prev==i)
        {
            auto [tmp_error, tmp_str]=solution(idx+1, i, len+1, w, arr);
            if(tmp_error + abs(arr[idx]-level[i]) + w < ret_error)
                ret_error=tmp_error + abs(arr[idx]-level[i]) + w, ret_str="0"+tmp_str;
        }
        else if(!idx)
        {
            auto [tmp_error, tmp_str]=solution(idx+1, i, len+2, w, arr);
            if(tmp_error + abs(arr[idx]-level[i]) + 2*w < ret_error)
                ret_error=tmp_error + abs(arr[idx]-level[i]) + 2*w, ret_str=code[i]+tmp_str;
        }
        else
        {
            auto [tmp_error, tmp_str]=solution(idx+1, i, len+3, w, arr);
            if(tmp_error + abs(arr[idx]-level[i]) + 3*w < ret_error)
                ret_error=tmp_error + abs(arr[idx]-level[i]) + 3*w, ret_str="1"+code[i]+tmp_str;
        }
    }
    return dp[idx][prev][len]={ret_error, ret_str};
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n, w; cin >> n >> w;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    auto [c, s]=solution(0, 4, 0, w, arr);
    cout << c << '\n' << s;
}

/*
    
*/