// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

string s;

int decision(int n)
{
    
}

int optimize()
{
    int lo=0, hi=200000, ans;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(decision(mid))
        {
            ans=mid;
            lo=mid+1;
        }
        else
            hi=mid-1;
    }
    return ans;
}

int main(void)
{
    cin >> s;
    printf("%d", optimize());
}

/*
      
*/