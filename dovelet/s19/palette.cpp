// http://220.89.64.243/30stair/palette/palette.php?pname=palette
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    string s; cin >> s;
    vector<char> palette(3);

    // // AAA가 처음이라면?
    // int start=0, used=0;
    // for(; used<3; start++)
    // {
    //     if(find(palette.begin(), palette.end(), s[start]) == palette.end())
    //         palette[used++]=s[start];
    // }

    int cnt=0;
    for(int i=0; i<s.length(); i++)
    {
        // 지금 상태로 그릴 수 있는지 확인
        if(palette[0]!=s[i] and palette[1]!=s[i] and palette[2]!=s[i])
        {
            // 가장 나중에 사용할 색을 제거
            int a=s.substr(i).find(palette[0]);
            int b=s.substr(i).find(palette[1]);
            int c=s.substr(i).find(palette[2]);
            if(a==-1) a=INT32_MAX;
            if(b==-1) b=INT32_MAX;
            if(c==-1) c=INT32_MAX;

            int target=max({a,b,c});
            if(target==a) palette[0]=s[i];
            else if(target==b) palette[1]=s[i];
            else if(target==c) palette[2]=s[i];
            cnt++;
        }
    }
    printf("%d", max(cnt-3, 0)); // 두 가지 색만 사용하면 cnt-3 == -1
}

/*
    
*/