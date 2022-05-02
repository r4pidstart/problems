// https://www.acmicpc.net/problem/7575
// 2022-05-03 00:11:00 24ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    char code[100][6*1010];
    char target1[6*1010]={}, target2[6*1010]={};
    for(int i=0; i<n; i++)
    {
        int tmp; scanf("%d", &tmp);
        getchar();
        if(!i) fgets(code[i]+2, 6*1010, stdin), code[0][0]='0', code[0][1]=' ';
        else fgets(code[i], 6*1010, stdin);

        // 문자열 뒤 공백, 개행 제거
        int cur=strlen(code[i]);
        while(--cur)
            if(code[i][cur] == ' ' or code[i][cur] == '\n') code[i][cur]='\0';
            else break;
    }

    int lo=0, hi=0, cnt=0;
    while(++hi and cnt != k)
        if(code[0][hi] == ' ' or code[0][hi] == '\0') cnt++;
    hi--;

    int lim=strlen(code[0]);
    while(true)
    {
        while(code[0][++hi] != ' ' and code[0][hi] != '\0');
        while(code[0][++lo] != ' ' and code[0][hi] != '\0');
        lo++;
        if(hi > lim) break;

        strncpy(target1, code[0]+lo, hi-lo);
        strncpy(target2, code[0]+lo, hi-lo);
        target2[hi-lo]=target1[hi-lo]='\0';
        reverse(target2, target2+hi-lo);
        int s=0, e=0; 
        for(int i=0; i<=hi-lo; i++)
            if(target2[i] == ' ' or target2[i] == '\0')
            {
                s=e, e=i;
                reverse(target2+s, target2+e);
                e++;
            }

        int flag=0;        
        for(int i=1; i<n; i++)
        {
            if(!strstr(code[i], target1) and !strstr(code[i], target2))
            {
                flag++;
                break;
            }
        }
        if(!flag)
            return !printf("YES");
    }
    printf("NO");
}

/*
    
*/