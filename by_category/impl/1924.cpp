// https://www.acmicpc.net/problem/1924
// 2022-03-08 19:15:16 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int x,y; scanf("%d%d", &x,&y);

    int days=y-1;
    while(--x)
    {
        if(x == 1 or x == 3 or x == 5 or x == 7 or x == 8 or x == 10 or x == 12)
            days+=31;
        else if(x == 2)
            days+=28;
        else
            days+=30;
    }

    string s[7]={"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    cout << s[days%7];
}

/*
    
*/