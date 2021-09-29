// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

vector<int> arr, cand;

int decision(int mid, int t)
{
    vector<int> tarr=arr;
    long long cnt=0;
    for(auto it=tarr.begin(); it<tarr.end()-1; it++)
    {
        if(*it - *(it+1) > mid)
        {
            int dif=*it - *(it+1) - mid;
            *it-=dif, cnt+=dif;
        }
        else if(*(it+1) - *it > mid)
        {
            int dif=*(it+1) - *it - mid;
            *(it+1)-=dif, cnt+=dif;
        }
    }

    for(auto it=tarr.rbegin(); it<tarr.rend()-1; it++)
    {
        if(*it - *(it+1) > mid)
        {
            int dif=*it - *(it+1) - mid;
            *it-=dif, cnt+=dif;
        }
        else if(*(it+1) - *it > mid)
        {
            int dif=*(it+1) - *it - mid;
            *(it+1)-=dif, cnt+=dif;
        }
    }

    if(t>=cnt) cand=tarr;
    return t>=cnt ? 1:0;
}

int main(void)
{
    // freopen("zivica.in.4", "r", stdin);
    int n,t; scanf("%d%d", &n,&t);
    arr.assign(n,0);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    int lo=0, hi=(int)10e9, ans=(int)10e9;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(decision(mid, t))
        {
            hi=mid-1;
            ans=mid;
        }
        else
            lo=mid+1;
    }

    // freopen("zivica.out.4", "r", stdin);
    // for(int i : cand)
    // {
    //     int tmp; scanf("%d", &tmp);
    //     if(tmp!=i) printf("expected %d but %d\n", tmp, i);
    // }
    for(auto i : cand)
        printf("%d ", i);
}

/*
    
*/