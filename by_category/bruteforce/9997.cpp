// https://www.acmicpc.net/problem/9997
// 2024-05-22 02:45:11
#include"bits/stdc++.h"
using namespace std;

int solution(int now, int now_mask, const vector<int>& mask)
{
    if(now==mask.size())
        return __builtin_popcount(now_mask)==26;

    return solution(now+1, now_mask|mask[now], mask)+solution(now+1, now_mask, mask);
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    vector<int> mask(n);
    for(int i=0; i<n; i++)
    {
        bitset<30> tmp;
        string s; cin >> s;
        for(char c : s)
            tmp[c-'a']=1;
        mask[i]=tmp.to_ulong();
    }

    cout << solution(0, 0, mask);
}

/*
    
*/