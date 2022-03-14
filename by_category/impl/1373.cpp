// https://www.acmicpc.net/problem/1373
// 2022-03-14 21:44:45 16ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    string ans="";
    int tmp=0, cnt=0;
    for(int i=s.length()-1; i>=0; i--)
    {
        if(cnt==3)
        {
            ans.push_back(tmp+'0');
            cnt=0, tmp=0, i++;
        }
        else
        {
            if(cnt==0) tmp+=1*(s[i]-'0');
            else if(cnt==1) tmp+=2*(s[i]-'0');
            else if(cnt==2) tmp+=4*(s[i]-'0');
            cnt++;
        }
    }
    ans.push_back(tmp+'0');

    reverse(ans.begin(), ans.end());
    cout << ans;
}

/*
    
*/