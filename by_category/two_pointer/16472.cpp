// https://www.acmicpc.net/problem/16472
// 2022-07-26 23:49:03  
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; string str;
    cin >> n >> str;

    int ans=0, s=0, e=0;
    vector<int> used(26);

    while(s<=e and e < str.size())
    {
        used[str[e++]-'a']++;
        
        int cnt=0;
        for(int i=0; i<26; i++)
            if(used[i]) cnt++;
        while(cnt > n)
        {
            used[str[s]-'a']--;
            if(!used[str[s++]-'a']) cnt--;
        }

        ans=max(ans, e-s);
    }

    printf("%d", ans);
}

/*
    
*/