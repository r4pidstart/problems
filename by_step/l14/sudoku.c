#include<stdio.h>

int board[9][9] ={0,};
int n=0;
int h[9]={0,}, v[9]={0,}, s[9]={0,};

int print_board(void)
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int horizental(int column)
{
    int tmp=45, tmpn=0, tmpi;
    for(int i=0; i<9; i++)
    {
        if(board[i][column]!=0)
            tmp-=board[i][column];
        else
        {
            tmpi=i;
            tmpn++;
        }
    }
    if(tmpn==1)
    {
        board[tmpi][column]=tmp;
        n--;
        h[column]=1;
    }
    else if(tmpn==0)
        h[column]=1;
}

int vertical(int row)
{
    int tmp=45, tmpn=0, tmpi;
    for(int i=0; i<9; i++)
    {
        if(board[row][i]!=0)
            tmp-=board[row][i];
        else
        {
            tmpi=i;
            tmpn++;
        }
    }
    if(tmpn==1)
    {
        board[row][tmpi]=tmp;
        n--;
        v[row]=1;
    }
    else if(tmpn==0)
        v[row]=1;
}

int square(int z)
{
    int tmp=45, tmpn=0, tmpi, tmpj;
    for(int i=z/3*3, k=i+3; i<k; i++)
        for(int j=z%3*3, l=j+3; j<l; j++)
        {
            if(board[i][j]!=0)
                tmp-=board[i][j];
            else
            {
                tmpi=i;
                tmpj=j;
                tmpn++;
            }
        }
    if(tmpn==1)
    {
        board[tmpi][tmpj]=tmp;
        n--;
        s[z]=1;
    }
    else if(tmpn==0)
        s[z]=1;
}

int check()
{
    for(int i=0; i<9; i++)
    {
        vertical(i);
        horizental(i);
        square(i);
    }

}

int sudoku()
{
    while(n)
    {
        for(int i=0; i<9; i++)
            if(!v[i])
                vertical(i);
            else if(!h[i])
                horizental(i);
            else if(!s[i])
                square(i);
    }
}


int main(void)
{
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
        {
            scanf("%d", &board[i][j]);
            if (board[i][j]==0)
                n++;
        }

    sudoku();
    print_board();
}