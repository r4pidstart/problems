// https://www.acmicpc.net/problem/17609
// 2022-06-13 01:14:27 104ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        string s; cin >> s;
        int l=0, r=s.length()-1;
        int is_pal=0, flag=0;
        while(l<=r)
        {
            if(flag) break;
            else if(s[l] == s[r])
                l++, r--;
            else
            {
                is_pal++;
                int l2=l+1, r2=r;
                while(l2<=r2)
                {
                    if(s[l2] == s[r2])
                        l2++, r2--;
                    else
                    {
                        flag++; 
                        break;
                    }
                }
                l2=l, r2=r-1;
                while(l2<=r2)
                {
                    if(s[l2] == s[r2])
                        l2++, r2--;
                    else
                    {
                        flag++; 
                        break;
                    }
                }
                if(flag != 2)
                {
                    printf("1");
                    break;
                }
            }
        }
        if(!is_pal)
            printf("0");
        else if(flag == 2)
            printf("2");
        printf("\n");
    }
}

/*
    
*/