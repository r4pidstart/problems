// https://www.acmicpc.net/problem/1027
// 2022-09-26 00:49:07 0ms
#include"bits/stdc++.h"
using namespace std;

double get_area(const pair<long,long> &one, const pair<long,long> &two, const pair<long,long> &three)
{
    return (one.first*two.second + two.first*three.second + three.first*one.second)-(two.first*one.second + three.first*two.second + one.first*three.second);
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n), cnt(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    for(int i=0; i<n; i++)
       for(int j=i+1; j<n; j++)
        {
            int flag=0;
            pair<long,long> s={i, arr[i]}, e={j, arr[j]};
            for(int k=i+1; k<=j-1; k++)
            {
                if(k==i or j==i) continue;
                if(get_area(s, e, make_pair(k, 0)) * get_area(s, e, make_pair(k, arr[k])) <= 0)
                    flag=1;
            }
            if(!flag) cnt[i]++, cnt[j]++;
        }
    printf("%d", *max_element(cnt.begin(), cnt.end()));
}

/*
    
*/