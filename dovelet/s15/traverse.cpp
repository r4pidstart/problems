// http://220.89.64.243/30stair/traverse/traverse.php?pname=traverse
//
#include<bits/stdc++.h>
using namespace std;

string pre, in;

void post(int root, int lIn, int rIn)
{
    for(int i=lIn; i<=rIn; i++)
        if(pre[root]==in[i]) // 루트를 찾았다면,
        {
            // 좌 우로 재귀
            post(root+1, lIn, i-1);
            post(root+i-lIn+1, i+1, rIn);
            printf("%c", pre[root]);
        }
}

int main(void)
{
        cin >> in >> pre;
        post(0, 0, pre.length()-1);
}

/*
    
*/