// https://www.acmicpc.net/problem/1259
// 2022-03-16 23:27:42 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    while(s != "0")
    {
        int flag=0;
        for(int i=0; i<s.length()/2; i++)
            if(s[i]!=s[s.length()-i-1])
                flag++;
        cout << (flag ? "no":"yes") << '\n';
        cin >> s;
    }
}

/*
    
*/