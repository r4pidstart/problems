#include<stdio.h>
#include<stdlib.h>

int board[10][10]={0,};

int print_board(void)
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int test(int row, int column, int k)
{
    for(int i=0; i<9; i++)
    {
        if(board[i][column]==k)
            return 1;
        if(board[row][i]==k)
            return 1;
    }
    for(int x=row/3*3, i=x+3; x<i; x++)
        for(int y=column/3*3, j=y+3; y<j; y++)
            if(board[x][y]==k)
                return 1;
    return 0;
}

int dfs(int index)
{
    if(index==81)
    {
        print_board();
        exit(0);
    }
    else
    {
        int y=index%9, x=index/9;
        if(board[x][y])
            dfs(index+1); 
        else
            for(int k=1; k<10; k++)
            {
                if(!test(x,y,k))
                {
                    board[x][y]=k;
                    dfs(index+1);
                    board[x][y]=0;
                }
            }
    }
}

int main(void)
{
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            scanf("%d", &board[i][j]);
        dfs(0);
}