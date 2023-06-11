// https://www.acmicpc.net/problem/2997
// 2023-06-12 04:47:58
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    vector<int> arr(3);
    for(int i=0; i<3; i++)
        scanf("%d", &arr[i]);

    for(int i=-200; i<=200; i++)
    {
        vector<int> tmp=arr;
        tmp.push_back(i);
        sort(tmp.begin(), tmp.end());
        
        int dif=tmp[1]-tmp[0];
        int flag=0;
        for(int j=0; j<3; j++)
            if(tmp[j+1]-tmp[j] != dif) flag=1;
        if(!flag)
            return !printf("%d", i);
    }
    assert(false);
}

/*
    
*/