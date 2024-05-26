// https://www.acmicpc.net/problem/22878
// 2024-04-28 11:12:00
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arrx(n), arry(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arrx[i]);
    for(int i=0; i<n; i++)
        scanf("%d", &arry[i]);
    
    vector<int> convertedx(n), convertedy(n);
    for(int i=0; i<n; i++)
    {
        convertedx[i]=arrx[i]-arry[i];
        convertedy[i]=arrx[i]+arry[i];
    }

    sort(arrx.begin(), arrx.end());
    sort(arry.begin(), arry.end());
    sort(convertedx.begin(), convertedx.end());
    sort(convertedy.begin(), convertedy.end());

    long converted_ans=0, sum_dif=0;
    long sumx=0, sumy=0;
    long sumx2=0, sumy2=0;
    for(int i=0; i<n; i++)
    {
        converted_ans+=(1L*convertedx[i]*i - sumx) + (1L*convertedy[i]*i - sumy);
        sumx+=convertedx[i], sumy+=convertedy[i];
        sum_dif+=(1L*arrx[i]*i - sumx2) + (1L*arry[i]*i - sumy2);
        sumx2+=arrx[i], sumy2+=arry[i];
    }
    printf("%ld", 2*sum_dif-converted_ans);
}

/*
    
*/