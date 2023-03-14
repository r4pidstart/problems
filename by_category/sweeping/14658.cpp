// https://www.acmicpc.net/problem/14658
// 2023-03-14 22:25:27
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
    freopen("tmp_input", "r", stdin);
#endif
    int n,m,l,k; scanf("%d%d%d%d", &n, &m, &l, &k);
    map<int, vector<int> > stars;
    vector<pair<int,int> > arr(k);
    for(int i=0; i<k; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    
    for(auto s1 : arr)
    {
        int target=s1.first;
        if(stars.find(target) == stars.end())
        {
            for(auto s2 : arr)
                if(target<=s2.first and s2.first<=target+l)
                    stars[target].push_back(s2.second);
        }
    }

    int ans=0;
    for(auto& it : stars)
    {
        auto& sorted=it.second;
        sort(sorted.begin(), sorted.end());

        int lo=0, hi=0;
        while(lo<sorted.size())
        {
            while(hi<sorted.size() and sorted[hi]<=sorted[lo]+l) hi++;
            ans=max(ans, hi-lo);
            lo++;
        }
    }
    printf("%d", k-ans);
}

/*

*/