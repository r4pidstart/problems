// https://www.acmicpc.net/problem/6987
// 2024-04-18 12:05:08
#include"bits/stdc++.h"
using namespace std;

int solution(int now, int target, vector<vector<int> >& arr)
{
    if(now==6)
    {
        int flag=0;
        for(int i=0; i<6; i++)
            flag+=accumulate(arr[i].begin(), arr[i].end(), 0);
        return !flag;
    }

    if(target==6)
        return arr[now][0] or arr[now][1] ? 0:solution(now+1, now+1, arr);

    if(target==now)
        return solution(now, target+1, arr);

    if(arr[now][0] and arr[target][2])
    {
        arr[now][0]--, arr[target][2]--;
        if(solution(now, target+1, arr))
            return 1;      
        arr[now][0]++, arr[target][2]++;
    }

    if(arr[now][2] and arr[target][0])
    {
        arr[now][2]--, arr[target][0]--;
        if(solution(now, target+1, arr))
            return 1;      
        arr[now][2]++, arr[target][0]++;
    }

    if(arr[now][1] and arr[target][1])
    {
        arr[now][1]--, arr[target][1]--;
        if(solution(now, target+1, arr))
            return 1;
        arr[now][1]++, arr[target][1]++;
    }

    if(solution(now, target+1, arr))
        return 1;

    return 0;
}

int main(void)
{
    int t=4;
    while(t--)
    {
        vector<vector<int> > arr(6, vector<int>(3));
        for(int i=0; i<6; i++)
            for(int j=0; j<3; j++)
                scanf("%d", &arr[i][j]);
        
        int flag=0, win_cnt=0, lose_cnt=0, draw_cnt=0;
        for(int i=0; i<6; i++)
        {
            if(accumulate(arr[i].begin(), arr[i].end(), 0)!=5)
                flag=1;
            win_cnt+=arr[i][0], lose_cnt+=arr[i][2], draw_cnt+=arr[i][1];
        }
        
        if(win_cnt!=lose_cnt) flag=1;
        if(draw_cnt&1) flag=1;

        printf("%d ", flag ? 0:solution(0, 0, arr));
    }
}

/*
    
*/