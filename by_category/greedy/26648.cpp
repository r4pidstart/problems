// https://www.acmicpc.net/problem/26648
// 2022-12-25 01:12:34
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    int prev=-1;
    vector<vector<int> > score(3, vector<int>(n));
    for(int j=0; j<3; j++)
        for(int i=0; i<n; i++)
            scanf("%d", &score[j][i]);

    for(int i=0; i<n; i++)
    {
        vector<int> arr={score[0][i], score[1][i], score[2][i]};
        sort(arr.begin(), arr.end());
        if(prev >= arr[2])
            return !printf("NO");
        prev = max(prev+1, arr[0]); 
    }
    printf("YES");
}

/*
    
*/