// https://www.acmicpc.net/problem/6503
// 2023-08-17 05:00:55
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int m; scanf("%d", &m);
    while(m)
    {
        cin >> ws;
        string s; getline(cin, s);

        vector<int> arr(256);
        int lo=0, hi=0, cnt=0, ans=0;
        while(hi<s.length())
        {
            if(cnt <= m)
            {
                if(!arr[s[hi++]]++) cnt++;
                if(cnt<=m) ans=max(ans, hi-lo);
            }
            else
                if(arr[s[lo++]]--==1) cnt--;
        }
        printf("%d\n", ans);
        scanf("%d", &m);
    }
}

/*
    
*/