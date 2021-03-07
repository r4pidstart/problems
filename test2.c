#include<stdio.h>

int board[9][9] = {0,};
int zero=0;

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

int check(void)
{
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            if(board[i][j]==0)
                return 0;
    return 1;
}

int dfs(int x, int y)
{
    if(x==8 && y==8)
    {   
        if(check())
            return 0;
    }
    else
    {
        for(int i=x; i<9; i++)
            for(int j=y; j<9; j++)
            {
                if(board[i][j]==0)
                    for(int k=1; k<10; k++)
                    {
                        if(test(i,j,k)==0)
                        {
                            board[i][j]=k;
                            dfs(i,j);
                        }
                    }
            }
    }
}

int main(void)
{
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
        {
            scanf("%d", &board[i][j]);
            zero++;
        }

        dfs(0,0);
    
    print_board();
}


