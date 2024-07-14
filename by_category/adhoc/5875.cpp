// https://www.acmicpc.net/problem/5875
// 2024-07-04 10:08:12
#include"bits/stdc++.h"
#define scanf(...) do not use thise
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    string s; cin >> s;
    vector<int> psum1(s.length()+2), psum2(s.length()+2);
    for(int i=1; i<=s.length(); i++)
        psum1[i]=psum1[i-1]+(s[i-1]=='(' ? 1:-1);
    for(int i=s.length(); i>=1; i--)
        psum2[i]=psum2[i+1]+(s[i-1]=='(' ? 1:-1);

    for(int i=1; i<=s.length(); i++)
        if(psum1[i]<0)
        {
            fill(psum1.begin()+i, psum1.end(), INT32_MAX/2);
            break;
        }
    for(int i=s.length(); i>=1; i--)
        if(psum2[i]>0)
        {
            fill(psum2.begin(), psum2.begin()+i+1, INT32_MAX/2);
            break;
        }
    
    int ans=0; 
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='(')
            ans+=(psum1[i]+psum2[i+2]-1==0);
        else
            ans+=(psum1[i]+psum2[i+2]+1==0);
    }
    cout << ans;
}

/*
      ( ) ( ( ) ) ) ) 
    0 1 0 1 2 1 0 -1 -2 0
    0 2 3 2 3 4 3 2 1 0
*/