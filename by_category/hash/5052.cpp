// https://www.acmicpc.net/problem/5052
// 2021-08-28 02:00:29 200ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        unordered_set<string> us;
        us.reserve(n);
        vector<string> strs(n);
        for(int i=0; i<n; i++)
            cin >> strs[i];

        sort(strs.begin(), strs.end());

        int flag=0;
        for(int i=0; i<n; i++)
        {
            if(flag) break;
            // check prefixes
            for(int j=1; j<=strs[i].length(); j++)
            {
                if(us.find(strs[i].substr(0,j)) != us.end()) // already exists
                    flag++;
            }
            us.insert(strs[i]);
        }

        if(flag) printf("NO\n");
        else printf("YES\n");
    }
}

/*

*/