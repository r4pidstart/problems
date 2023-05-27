// https://www.acmicpc.net/problem/1034
// 2023-05-28 02:34:43
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    m--;
    int day_per_month[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(n%4==0 and n%100!=0 or n%400==0) day_per_month[1]++;

    int cnt=0;
    for(int i=0; i<12; i++)
    {
        vector<vector<int> > arr(6, vector<int>(7));
        int day=1, w=0;
        while(day_per_month[i]--)
        {
            arr[w][m]=day++;
            m=(m+1)%7;
            if(m==0) w++;
        }

        for(int i=0; i<7; i++)
        {
            int tmp=0;
            for(int j=0; j<6; j++)
                if(arr[j][i]) tmp++;
            if(tmp==5) cnt++;
        }
    }
    printf("%d", cnt);
}

/*
    
*/