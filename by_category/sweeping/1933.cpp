// https://www.acmicpc.net/problem/1933
// 2024-03-06 21:29:55
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    // l h r
    vector<tuple<int, int, int> > arr(n);
    for(int i=0; i<n; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        arr[i]={a, b, c};
    }
    arr.push_back({1e9+1, 0, 1e9+1});

    sort(arr.begin(), arr.end(), [](auto a, auto b) -> bool {
        auto [aa, ab, ac]=a;
        auto [ba, bb, bc]=b;
        return make_tuple(aa, -ab, ac) < make_tuple(ba, -bb, bc);
    });

    // h l r
    set<tuple<int,int,int> > se;
    // r h l
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<> > pq;

    for(auto [l, h, r] : arr)
    {
        while(pq.size() and get<0>(pq.top()) < l)
        {
            int prev_height=get<0>(*prev(se.end()));

            auto [pr, ph, pl]=pq.top();
            pq.pop();
            se.erase({ph, pl, pr});
            while(pq.size() and get<0>(pq.top())==pr)
            {
                // 끝나는 지점이 같은 상자들은 모두 치워야
                auto [rr, hh, ll]=pq.top();
                pq.pop();

                se.erase({hh, ll, rr});
                ph=hh;
            }

            if(!se.size())
                printf("%d %d ", pr, 0);
            else if(prev_height != get<0>(*prev(se.end())))
                printf("%d %d ", pr, get<0>(*prev(se.end())));
        }
        
        if(h==0) continue; 

        if(!se.size() or get<0>(*prev(se.end())) < h)
            printf("%d %d ", l, h);
        pq.push({r, h, l});
        se.insert({h, l, r});
    }
}

/*
    
*/