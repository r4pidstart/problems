// https://www.acmicpc.net/problem/10096
// 2024-04-13 17:46:04
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    string s; cin >> s;

    if(n%2==0)
        return !printf("NOT POSSIBLE");

    string ans="";
    // 앞부분에 있을때 (pos(X) <= n/2)
    {
        int hi=n/2+1, flag=0;
        for(int i=0; i<n/2+1; i++)
        {
            if(s[i] != s[hi] or hi==n)
            {
                if(flag)
                {
                    flag=0;
                    break;
                }
                flag=1, hi--;
            }
            hi++;
        }
        if(flag)
            ans=s.substr(n/2+1);
    }

    // 뒤
    {
        int lo=0, flag=0;
        for(int i=n/2; i<n; i++)
        {
            if(s[i] != s[lo] or lo==n/2)
            {
                if(flag)
                {
                    flag=0;
                    break;
                }
                flag=1, lo--;
            }
            lo++;
        }
        if(flag and ans.size() and ans!=s.substr(0, n/2))
            return !printf("NOT UNIQUE");
        if(flag)
            ans=s.substr(0, n/2);
    }
    if(ans.size()==0)
        return !printf("NOT POSSIBLE");
    printf("%s", ans.c_str());
}

/*
    ㅇㅇㅇㅇ|Xㅇㅇㅇㅇ
    ㅇㅇXㅇㅇ|ㅇㅇㅇㅇ
    ㅇㅇㅇㅇ|ㅇㅇXㅇㅇ

*/