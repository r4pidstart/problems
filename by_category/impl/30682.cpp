// https://www.acmicpc.net/problem/30682
// 2024-05-07 21:04:33
#include"bits/stdc++.h"
using namespace std;

inline int get_texi_dist(int x1, int y1, int x2, int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<tuple<int, int, int> > arr(n);
    for(int i=0; i<n; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        arr[i]={a,b,c};
    }

    int lbx, lby, rtx, rty;
    scanf("%d%d%d%d", &lbx, &lby, &rtx, &rty);
    int lx=rtx-lbx+1, ly=rty-lby+1;

    long ans=0;
    // for(auto& [x, y, b] : arr)
    for(int I=0; I<n; I++)
    {
        int x=get<0>(arr[I]), y=get<1>(arr[I]), b=get<2>(arr[I]);

        // inside the area
        if(lbx<=x and x<=rtx and lby<=y and y<=rty)
        {
            ans+=1L*b*(2*b*b+1)/3;
            // check the border of area
            for(int i=lbx-b; i<=rtx+b; i++)
            {
                int target_t=b-get_texi_dist(x, y, i, rty+1);
                int target_b=b-get_texi_dist(x, y, i, lby-1);

                if(target_t > 0)
                    ans-=target_t*(target_t+1)/2;
                if(target_b > 0)
                    ans-=target_b*(target_b+1)/2;
            }

            for(int i=lby; i<=rty; i++)
            {
                int target_l=b-get_texi_dist(x, y, lbx-1, i);
                int target_r=b-get_texi_dist(x, y, rtx+1, i);

                if(target_l > 0)
                    ans-=target_l*(target_l+1)/2;
                if(target_r > 0)
                    ans-=target_r*(target_r+1)/2;
            }
        }
        // outside the area
        else
        {
            if(x<lbx)
            {
                for(int i=lby; i<=rty; i++)
                {
                    int target=b-get_texi_dist(x, y, lbx, i);
                    if(target > 0)
                    {
                        ans+=target*(target+1)/2;
                        if(target > lx)
                            ans-=(target-lx)*(target-lx+1)/2;
                    }
                }
            }
            else if(rtx<x)
            {
                for(int i=lby; i<=rty; i++)
                {
                    int target=b-get_texi_dist(x, y, rtx, i);
                    if(target > 0)
                    {
                        ans+=target*(target+1)/2;
                        if(target > lx)
                            ans-=(target-lx)*(target-lx+1)/2;
                    }
                }
            }
            else if(y<lby)
            {
                for(int i=lbx; i<=rtx; i++)
                {
                    int target=b-get_texi_dist(x, y, i, lby);
                    if(target > 0)
                    {
                        ans+=target*(target+1)/2;
                        if(target > ly)
                            ans-=(target-ly)*(target-ly+1)/2;
                    }
                }
            }
            else if(rty<y)
            {
                for(int i=lbx; i<=rtx; i++)
                {
                    int target=b-get_texi_dist(x, y, i, rty);
                    if(target > 0)
                    {
                        ans+=target*(target+1)/2;
                        if(target > ly)
                            ans-=(target-ly)*(target-ly+1)/2;
                    }
                }
            }
        }
    }

    printf("%ld", ans);
}

/*
    
*/