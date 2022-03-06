// https://www.acmicpc.net/problem/2671
// 2022-03-06 15:12:14 0ms
#include<bits/stdc++.h>
using namespace std;

// (100~1~|01)~
int main(void)
{
    string s; cin >> s;
    int cur=0, flag=0;
    while(cur < s.length())
    {
        if(flag)
        {
            if(cur+1 < s.length() and s[cur] == '0' and s[cur+1] == '1')
                cur+=2, flag=0;
            else 
                flag=0, cur--;
        }
        if(s[cur] == '0') // pattern 1
        {
            if(s[cur+1] == '1')
                cur+=2;
            else
                return !printf("NOISE");
        }
        else if(s[cur] == '1') // pattern 2
        {
            int cur2=cur+1;
            while(cur2 < s.length() and s[cur2] != '1') cur2++;
            if(s[cur2] != '1' or cur2 - cur - 1 < 2) // 1과 1 사이의 0의 갯수
                return !printf("NOISE");
            else
                cur=cur2+1;

            // 패턴 뒤 1 처리
            while(cur < s.length() and s[cur] == '1') cur++, flag=1;   
        }
    }
    printf("SUBMARINE");
}

/*
    
*/