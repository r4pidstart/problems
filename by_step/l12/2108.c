#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void)
{
    int n,t, min=8000, max=0, mode_i=0, mode_n, mid_n, mode_N=0, sum_i=0;
    double sum_n=0;
    scanf("%d", &n);
    int table[8002]={0,};
    for(int i=0; i<n; i++)
    {    
        scanf("%d", &t);
        table[t+4000]++;
    }

    for(int i=0; i<8001; i++)
        if(table[i])
        {                
            min=i;
            break;
        }

    for(int i=8000; i>0; i--)
        if(table[i])
        {        
            max=i;
            break;
        }

    for(int i=0; i<8001; i++)
    {
        if(table[i]==mode_i && mode_N!=2)
        {
            mode_N++;
            mode_n=i;
        }
        if(table[i]>mode_i)
        {           
            mode_N=1;     
            mode_i=table[i];
            mode_n=i;
        }
        sum_n+=(i*table[i]);
    }
    

    for(int i=0; i<8001; i++)
    {
        sum_i+=table[i];

        if(sum_i>=n/2+1)
        {        
            mid_n=i;
            break;
        }
    }
    printf("%.0f\n%d\n%d\n%d\n", floor(sum_n/n+0.5)-4000, mid_n-4000, mode_n-4000, abs(max-min));
}
