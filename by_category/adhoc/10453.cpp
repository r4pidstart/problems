// https://www.acmicpc.net/problem/10453
// 2023-12-02 22:42:40
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        string a,b; cin >> a >> b;
        vector<int> arr;
        for(int i=0; i<a.size(); i++)
            if(a[i]=='b') arr.push_back(i);

        int ans=0, idx=0;
        for(int i=0; i<b.size(); i++)
            if(b[i]=='b') ans+=abs(i-arr[idx++]); 
        printf("%d\n", ans);
    }
}

/*
    
*/