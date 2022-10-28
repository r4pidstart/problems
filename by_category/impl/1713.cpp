// https://www.acmicpc.net/problem/1713
// 2022-10-29 02:48:44
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n, c; scanf("%d%d", &n, &c);
    vector<pair<int, pair<int,int> > > frame(n);
    
    for(int i=0; i<c; i++)
    {
        int a; scanf("%d", &a);
        int target=0, flag=0;
        for(int j=0; j<n; j++)
        {
            if(frame[j].first == a) flag=1, target=j, frame[target].second.first++;
            if(!flag and frame[target].second > frame[j].second) target=j;
        }

        if(!flag)
            frame[target]={a, {1,i}};
    }

    sort(frame.begin(), frame.end());
    for(auto it : frame)
        if(it.first) printf("%d ", it.first);
}

/*
    
*/