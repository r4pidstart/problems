// https://www.acmicpc.net/problem/14254
// 2023-05-12 00:07:55
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s; cin >> s;
    int k, ans=0; cin >> k;

    if(k*2<=s.length() or k==s.length())
    {
        for(int i=0; i<k; i++)
            ans+=s[i]!=s[i+s.length()-k];
    }
    else
    {
        vector<int> checked(s.length());
        int duration=s.length()-k;
        for(int i=0; i<k; i++)
        {
            if(checked[i]) continue;
            vector<int> cnt(26);
            for(int j=i; j<s.length(); j+=duration)
            {
                cnt[s[j]-'a']++;
                checked[j]=1;
            }
            
            ans+=accumulate(cnt.begin(), cnt.end(), 0) - *max_element(cnt.begin(), cnt.end());
        }
    }
    printf("%d", ans);
}

/*
    
*/