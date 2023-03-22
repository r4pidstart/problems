// https://www.acmicpc.net/problem/25206
// 2023-03-23 01:31:44
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s;

    int cnt=0;
    double weighted_sum=0;
    while(cin >> s)
    {
        cin >> s;
        int tmp=stof(s);
        cnt+=tmp;

        cin >> s;
        if(s=="A+") weighted_sum+=tmp*4.5;
        else if(s=="A0") weighted_sum+=tmp*4.0;
        else if(s=="B+") weighted_sum+=tmp*3.5;
        else if(s=="B0") weighted_sum+=tmp*3.0;
        else if(s=="C+") weighted_sum+=tmp*2.5;
        else if(s=="C0") weighted_sum+=tmp*2.0;
        else if(s=="D+") weighted_sum+=tmp*1.5;
        else if(s=="D0") weighted_sum+=tmp*1.0;
        else if(s=="P") cnt-=tmp;
    }
    printf("%lf", weighted_sum/cnt);
}

/*
    
*/