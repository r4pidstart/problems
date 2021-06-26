// 6-5 BOARDCOVER
// https://algospot.com/judge/problem/read/BOARDCOVER
// 2021-06-27 01:53:06 4ms
#include<bits/stdc++.h>
using namespace std;

/*
만들어질 수 있는 모양
ㅇㅁ ... 1
ㅁ

ㅇ ... 2
ㅁㅁ

ㅇㅁ ... 3
  ㅁ

  ㅇ ... 4
ㅁㅁ
*/

int h,w;

int fill_board(vector<vector<int> > board, int cnt)
{
    if(cnt==0) return 1;

    int ret=0;

    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
        {
            if(board[i][j]==0)
            {
                int flag=0;
                if(i+1 < h && j+1 < w && !board[i+1][j] && !board[i][j+1]) // 1번경우
                {
                    board[i+1][j]=1, board[i][j+1]=1, board[i][j]=1;
                    ret+=fill_board(board, cnt-3);
                    board[i+1][j]=0, board[i][j+1]=0, board[i][j]=0;
                }
                else flag++;

                if(i+1 < h && j+1 < w && !board[i+1][j] && !board[i+1][j+1]) // 2번경우
                {
                    board[i+1][j]=1, board[i+1][j+1]=1, board[i][j]=1;
                    ret+=fill_board(board, cnt-3);
                    board[i+1][j]=0, board[i+1][j+1]=0, board[i][j]=0;
                }
                else flag++;

                if(i+1 < h && j+1 < w && !board[i][j+1] && !board[i+1][j+1]) // 3번경우
                {
                    board[i][j+1]=1, board[i+1][j+1]=1, board[i][j]=1;
                    ret+=fill_board(board, cnt-3);
                    board[i][j+1]=0, board[i+1][j+1]=0, board[i][j]=0;
                }
                else flag++;

                if(i+1 < h && j-1 >= 0 && !board[i+1][j-1] && !board[i+1][j]) // 4번경우
                {
                    board[i+1][j-1]=1, board[i+1][j]=1, board[i][j]=1;
                    ret+=fill_board(board, cnt-3);
                    board[i+1][j-1]=0, board[i+1][j]=0, board[i][j]=0;
                }
                else flag++;
                
                if(flag==4) // 더 이상 채우는것이 불가능한 경우
                    return 0;
                else
                    return ret;
            }
        }
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int cnt=0; scanf("%d%d", &h,&w);
        vector<vector<int> > board(h, vector<int>(w, 0));
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                char tmp; scanf(" \n%c", &tmp);
                if(tmp=='#') board[i][j]=1;
                else cnt++;
            }
        }
        if(cnt%3!=0)
            printf("0\n");
        else
            printf("%d\n", fill_board(board, cnt));
    }
}