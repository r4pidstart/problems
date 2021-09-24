// https://www.acmicpc.net/problem/1759
// 2021-09-25 03:29:39 0ms
#include<bits/stdc++.h>
using namespace std;

vector<char> pass;
void btrk(int n, int c, int l, vector<char>& ch)
{
    if(c==l)
    {
        // 모음/자음 개수 체크
        int vowel=0, consonant=0;
        for(char c : pass) if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') vowel++; else consonant++;
        if(vowel<1 || consonant<2) return;
        for(char c : pass) printf("%c", c);
        printf("\n");
    }
    else
    {
        if(n < ch.size())
        {
            pass[c]=ch[n];
            btrk(n+1, c+1, l, ch); // 사용 하는 경우
            btrk(n+1, c, l, ch); // 사용 안 하는 경우
        }
    }
}

int main(void)
{
    int l,c; scanf("%d%d", &l,&c);
    vector<char> ch(c);
    pass.assign(l,0);
    for(int i=0; i<c; i++)
        scanf(" %c", &ch[i]);
    sort(ch.begin(), ch.end());
    btrk(0,0,l,ch);
}

/*
    
*/