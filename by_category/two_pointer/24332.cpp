// https://www.acmicpc.net/problem/24332
// 2022-05-02 00:32:37 242ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    cin.tie(NULL)->sync_with_stdio(false);
    string s; 
    getline(cin, s);
    int lo=0, hi=0;
    int anslo=0, anshi=0;
    vector<int> cnt(200);
    while(hi < s.length())
    {
        if(cnt[s[hi]]++)
        {
            while(s[lo++] != s[hi])
                cnt[s[lo-1]]--;
            cnt[s[hi]]--;
        }
        hi++;
        if(anshi - anslo <= hi - lo)
            anshi=hi, anslo=lo;
    }
    cout << anshi-anslo << ' ' << anslo << '\n';
    for(int i=0; i<anshi-anslo; i++)
        cout << s[anslo+i];
}

/*
    
*/