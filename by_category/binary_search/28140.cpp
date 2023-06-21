// https://www.acmicpc.net/problem/28140
// 2023-06-22 03:47:31
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,q; scanf("%d%d", &n, &q);
    // string s; cin >> s;
    char s[1000000]; scanf("%s", s);
    vector<int> idx_r, idx_b;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='R') idx_r.push_back(i);
        else if(s[i]=='B') idx_b.push_back(i);
    }
    idx_r.insert(idx_r.end(), {INT32_MAX, INT32_MAX});
    idx_b.insert(idx_b.end(), {INT32_MAX, INT32_MAX});

    while(q--)
    {
        int flag=0;
        int a,b; scanf("%d%d", &a, &b);
        b++;

        auto itr=lower_bound(idx_r.begin(), idx_r.end(), a);
        if(*itr < b and *(itr+1) < b)
        {
            int i=*(itr+1);
            auto itb=lower_bound(idx_b.begin(), idx_b.end(), i);
            if(*itb < b and *(itb+1) < b)
                flag=1, printf("%d %d %d %d\n", *itr, *(itr+1), *itb, *(itb+1));
        }
        if(!flag)
            printf("-1\n");
    }
}

/*
    
*/