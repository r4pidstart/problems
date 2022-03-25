// https://www.acmicpc.net/problem/15664
// 2022-03-26 06:09:21 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<int> arr(n), combi(n);
    fill(combi.begin(), combi.begin()+m, 1);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());

    set<vector<int> > se;
    do
    {
        vector<int> tmp;
        for(int i=0; i<n; i++)
            if(combi[i]) tmp.push_back(arr[i]);
        se.insert(tmp);
    } while (prev_permutation(combi.begin(), combi.end()));
    
    for(auto v : se)
    {
        for(int i : v)
            printf("%d ", i);
        printf("\n");
    }
}

/*
    
*/