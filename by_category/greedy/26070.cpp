// https://www.acmicpc.net/problem/26070
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    vector<int> hungry(3), coupon(3);
    for(int i=0; i<3; i++)
        scanf("%d", &hungry[i]);
    for(int i=0; i<3; i++)
        scanf("%d", &coupon[i]);

    long cnt=0;

    for(int i=0; i<3; i++)
    {
        int tmp=min(hungry[i], coupon[i]);
        hungry[i]-=tmp, coupon[i]-=tmp;
        cnt+=tmp;
    }

    // 0 -> 1, 1 -> 2, 2 -> 3
    for(int i=2; i>=0; i--)
    {
        int tmp=coupon[i]/3;
        coupon[i]-=tmp*3, coupon[(i+1)%3]+=tmp;
        for(int i=0; i<3; i++)
        {
            int tmp=min(hungry[i], coupon[i]);
            hungry[i]-=tmp, coupon[i]-=tmp;
            cnt+=tmp;
        }
    }

    for(int i=2; i>=0; i--)
    {
        int tmp=coupon[i]/3;
        coupon[i]-=tmp*3, coupon[(i+1)%3]+=tmp;
        for(int i=0; i<3; i++)
        {
            int tmp=min(hungry[i], coupon[i]);
            hungry[i]-=tmp, coupon[i]-=tmp;
            cnt+=tmp;
        }
    }


    printf("%ld", cnt);
}

/*
    
*/