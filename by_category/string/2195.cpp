// https://www.acmicpc.net/problem/2195
// 2021-10-02 00:23:15 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s1, s2;
    cin >> s1 >> s2;

    int cur=0, cnt=0;
    while(cur < s2.length())
    {
        // 한 칸씩 늘리면서 최대한 긴 문자열 찾기
        auto found=1; // 찾은 문자열 길이
        for(int i=1; cur+i<=s2.length(); i++)
        {
            auto res=s1.find(s2.substr(cur, i));
            if(res!=string::npos) found=i;
            else break;
        }
        cur+=found, cnt++;
    }
    printf("%d", cnt);
}

/*
    
*/