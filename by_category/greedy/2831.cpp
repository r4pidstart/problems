// https://www.acmicpc.net/problem/2831
// 2023-09-22 23:28:36
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    multiset<int> man, woman_lower, woman_higher;
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        man.insert(a);
    }
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        if(a<0)
            woman_lower.insert(-a);
        else
            woman_higher.insert(a);
    }

    int cnt=0;
    for(int i : man)
    {
        if(i<0) // wants lower woman
        {
            auto it=woman_higher.lower_bound(-i);
            if(it!=woman_higher.begin())
                cnt++, woman_higher.erase(prev(it));
        }
        else 
        {
            auto it=woman_lower.upper_bound(i);
            if(it!=woman_lower.end())
                cnt++, woman_lower.erase(it);
        }
    }
    printf("%d", cnt);
}

/*
    
*/