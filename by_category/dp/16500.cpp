// https://www.acmicpc.net/problem/16500 
// 2023-10-28 04:36:52  
#include"bits/stdc++.h"
using namespace std;

int btrk(const string& target, int idx, const vector<string>& arr)
{
    static vector<int> memo(target.size()+1, -1);
    if(memo[idx] != -1)
        return memo[idx];
    
    if(idx==target.size())
        return memo[idx]=1;
    
    for(string s : arr)
    {
        if(target.substr(idx, s.size()) != s) 
            continue;
        if(btrk(target, idx+s.length(), arr))
            return memo[idx]=1;
    }

    return memo[idx]=0;
}

int main(void)
{
#ifdef LOCAL
#endif
    string s; cin >> s;
    int n; cin >> n;
    vector<string> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    printf("%d", btrk(s, 0, arr));
}

/*
    
*/