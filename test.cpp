// https://www.acmicpc.net/problem/
// 
#include<bits/stdc++.h>
using namespace std;

#define cb(x,y,z) cube[x][y][z] 
vector<vector<char> > cube[6];
char color[6]={'w','y','r','o','g','b'};
// U,w:0 D,y:1 F,r:2 B,o:3 L,g:4 R,b:5

void init(void)
{
    for(int k=0; k<6; k++)
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                cube[k][i][j]=color[k];
}

void printcube(int t)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
            printf("%c", cube[t][i][j]);
        printf("\n");
    }
}

void rotate(char side, char direction)
{
    int count=direction=='+' ? 1:3; // 시계방향은 1번 돌리고, 반시계방향은 3번 돌림
    int target;
    if(side=='U')
        target=0;
    else if(side=='D')
        target=1;
    else if(side=='F')
        target=2;
    else if(side=='B')
        target=3;
    else if(side=='L')
        target=4;
    else if(side=='R')
        target=5;

    // rotate target side
    vector<vector<char> > tmptop(3,vector<char>(3,0));
    for(int k=0; k<count; k++)
    {
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                tmptop[j][2-i]=cube[target][i][j];
        cube[target]=tmptop;
    }

    // rotate other side
    if(side=='L')
    {
        for(int c=0; c<count; c++)
        {
        //     char tmp[3]={cube[0][0][0], cube[0][1][0], cube[0][2][0]};
        //     // 3->0
        //     cube[0][0][0]=cube[3][0][0], cube[0][1][0]=cube[3][1][0], cube[0][2][0]=cube[3][2][0];
        //     // 1->3
        //     cube[3][0][0]=cube[1][0][0], cube[3][1][0]=cube[1][1][0], cube[3][2][0]=cube[1][2][0];
        //     // 2->1
        //     cube[1][0][0]=cube[2][0][0], cube[1][1][0]=cube[2][1][0], cube[1][2][0]=cube[2][2][0];
        //     // 0->2
        //     cube[2][0][0]=tmp[0], cube[2][1][0]=tmp[1], cube[2][2][0]=tmp[2];

            char tmp[3]={cb(0,0,0), cb(0,1,0), cb(0,2,0)};
            cb(0,0,0)=cb(3,0,0), cb(0,1,0)=cb(3,1,0), cb(0,2,0)=cb(3,2,0);
            cb(3,0,0)=cb(1,0,0), cb(3,1,0)=cb(1,1,0), cb(3,2,0)=cb(1,2,0);
            cb(1,0,0)=cb(2,0,0), cb(1,1,0)=cb(2,1,0), cb(1,2,0)=cb(2,2,0);
            cb(2,0,0)=tmp[0], cb(2,1,0)=tmp[1], cb(2,2,0)=tmp[2];

        }
    }
    else if(side=='R')
    {
        for(int c=0; c<count; c++)
        {
            // char tmp[3]={cube[0][2][2], cube[0][1][2], cube[0][0][2]};
            // // 2->0
            // cube[0][2][2]=cube[2][2][2], cube[0][1][2]=cube[2][1][2], cube[0][0][2]=cube[2][0][2];
            // // 1->2
            // cube[2][2][2]=cube[1][2][2], cube[2][1][2]=cube[1][1][2], cube[2][0][2]=cube[1][0][2];
            // // 3->1
            // cube[1][2][2]=cube[3][2][2], cube[1][1][2]=cube[3][1][2], cube[1][0][2]=cube[3][0][2];
            // // 0->3
            // cube[3][2][2]=tmp[0], cube[3][1][2]=tmp[1], cube[3][0][2]=tmp[2];

            char tmp[3]={cb(0,0,2), cb(0,1,2), cb(0,2,2)};
            cb(0,0,2)=cb(2,0,2), cb(0,1,2)=cb(2,1,2), cb(0,2,2)=cb(2,2,2);
            cb(2,0,2)=cb(1,0,2), cb(2,1,2)=cb(1,1,2), cb(2,2,2)=cb(1,2,2);
            cb(1,0,2)=cb(3,0,2), cb(1,1,2)=cb(3,1,2), cb(1,2,2)=cb(3,2,2);
            cb(3,0,2)=tmp[0], cb(3,1,2)=tmp[1], cb(3,2,2)=tmp[2];
        }
    }
    else if(side=='U')
    {
        for(int c=0; c<count; c++)
        {
            // char tmp[3]={cube[2][0][0], cube[2][0][1], cube[2][0][2]};
            // // 5->2
            // cube[2][0][0]=cube[5][0][0], cube[2][0][1]=cube[5][0][1], cube[2][0][2]=cube[5][0][2];
            // // 3->5
            // cube[5][0][0]=cube[3][2][2], cube[5][0][1]=cube[3][2][1], cube[5][0][2]=cube[3][2][0];
            // // 4->3
            // cube[3][2][2]=cube[4][0][0], cube[3][2][1]=cube[4][0][1], cube[3][2][0]=cube[4][0][2];
            // // 2->4
            // cube[4][0][0]=tmp[0], cube[4][0][1]=tmp[1], cube[4][0][2]=tmp[2];

            char tmp[3]={cb(3,2,0), cb(3,2,1), cb(3,2,2)};
            cb(3,2,2)=cb(4,0,0), cb(3,2,1)=cb(4,0,1), cb(3,2,0)=cb(4,0,2);
            cb(4,0,0)=cb(2,0,0), cb(4,0,1)=cb(2,0,1), cb(4,0,2)=cb(2,0,2);
            cb(2,0,0)=cb(5,0,0), cb(2,0,1)=cb(5,0,1), cb(2,0,2)=cb(5,0,2);
            cb(5,0,2)=tmp[0], cb(5,0,1)=tmp[1], cb(5,0,0)=tmp[2];
        }
    }
    else if(side=='D')
    {
        for(int c=0; c<count; c++)
        {
            // char tmp[3]={cube[2][2][0], cube[2][2][1], cube[2][2][2]};
            // // 4->2
            // cube[2][2][0]=cube[4][2][0], cube[2][2][1]=cube[4][2][1], cube[2][2][2]=cube[4][2][2];
            // // 3->4
            // cube[4][2][0]=cube[3][0][2], cube[4][2][1]=cube[3][0][1], cube[4][2][2]=cube[3][0][0];
            // // 5->3
            // cube[3][0][2]=cube[5][2][0], cube[3][0][1]=cube[5][2][1], cube[3][0][0]=cube[5][2][2];
            // // 2->5
            // cube[5][2][0]=tmp[0], cube[5][2][1]=tmp[1], cube[5][2][2]=tmp[2];
            
            char tmp[3]={cb(2,2,0), cb(2,2,1), cb(2,2,2)};
            cb(2,2,0)=cb(5,2,0), cb(2,2,1)=cb(5,2,1), cb(2,2,2)=cb(5,2,2);
            cb(5,2,0)=cb(3,0,2), cb(5,2,1)=cb(3,0,1), cb(5,2,2)=cb(3,0,0);
            cb(3,0,0)=cb(4,2,2), cb(3,0,1)=cb(4,2,1), cb(3,0,2)=cb(4,2,0);
            cb(4,2,0)=tmp[0], cb(4,2,1)=tmp[1], cb(4,2,2)=tmp[2];
        }
    }
    else if(side=='F')
    {
        for(int c=0; c<count; c++)
        {
            // char tmp[3]={cube[0][2][0], cube[0][2][1], cube[0][2][2]};
            // // 4->0
            // cube[0][2][0]=cube[4][2][2], cube[0][2][1]=cube[4][1][2], cube[0][2][2]=cube[4][0][2];
            // // 1->4
            // cube[4][0][2]=cube[1][0][0], cube[4][1][2]=cube[1][0][1], cube[4][2][2]=cube[1][0][2];
            // // 5->1
            // cube[1][0][0]=cube[5][2][0], cube[1][0][1]=cube[5][1][0], cube[1][0][2]=cube[5][0][0];
            // // 0->5
            // cube[5][0][0]=tmp[1]?, cube[5][1][0]=tmp[1], cube[5][2][0]=tmp[2]; 

            char tmp[3]={cb(0,2,0), cb(0,2,1), cb(0,2,2)};
            cb(0,2,0)=cb(4,2,2), cb(0,2,1)=cb(4,1,2), cb(0,2,2)=cb(4,0,2);
            cb(4,0,2)=cb(1,0,0), cb(4,1,2)=cb(1,0,1), cb(4,2,2)=cb(1,0,2);
            cb(1,0,0)=cb(5,2,0), cb(1,0,1)=cb(5,1,0), cb(1,0,2)=cb(5,0,0);
            cb(5,0,0)=tmp[0], cb(5,1,0)=tmp[1], cb(5,2,0)=tmp[2];
        }
    }
    else if(side=='B')
    {
        for(int c=0; c<count; c++)
        {
            // char tmp[3]={cube[0][0][2], cube[0][0][1], cube[0][0][0]};
            // // 5->0
            // cube[0][0][2]=cube[5][2][2], cube[0][0][1]=cube[5][1][2], cube[0][0][0]=cube[5][0][2];
            // // 1->5
            // cube[5][2][2]=cube[1][2][0], cube[5][1][2]=cube[1][2][1], cube[5][0][2]=cube[1][2][2];
            // // 4->1
            // cube[1][2][0]=cube[4][0][0], cube[1][2][1]=cube[4][1][0], cube[1][2][2]=cube[4][2][0];
            // // 0->4
            // cube[4][0][0]=tmp[0], cube[4][1][0]=tmp[1], cube[4][2][0]=tmp[2];

            char tmp[3]={cb(1,2,0), cb(1,2,1), cb(1,2,2)};
            cb(1,2,0)=cb(4,0,0), cb(1,2,1)=cb(4,1,0), cb(1,2,2)=cb(4,2,0);
            cb(4,0,0)=cb(0,0,2), cb(4,1,0)=cb(0,0,1), cb(4,2,0)=cb(0,0,0);
            cb(0,0,2)=cb(5,2,2), cb(0,0,1)=cb(5,1,2), cb(0,0,0)=cb(5,0,2);
            cb(5,2,2)=tmp[0], cb(5,1,2)=tmp[1], cb(5,2,0)=tmp[2];
        }
    }
    // printcube(0);
}

int main(void)
{
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<6; i++)
        cube[i].assign(3, vector<char>(3,0));
    while(t--) 
    {
        init();
        int c; cin >> c;
        for(int i=0; i<c; i++)
        {
            string s; cin >> s;
            rotate(s[0], s[1]);
        }
        printcube(0);
    }   
}

/*

*/
