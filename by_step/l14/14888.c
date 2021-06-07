#include<stdio.h>

int mark[4]; // + - * /
int num[11];
int arr[10];
int n, min=1000000000, max=-1000000000;
int tmp;

int calculate(void)
{
    int i=1, tmp=num[0];
    while(num[i])
    {
        if(arr[i-1]==0)
            tmp+=num[i];
        else if(arr[i-1]==1)
            tmp-=num[i];
        else if(arr[i-1]==2)
            tmp*=num[i];
        else if(arr[i-1]==3)
            tmp/=num[i];
        i++;
    }
    return tmp;
}

int backtracking(int index)
{
    if(index==n-1)
    {
        if(calculate()<min)
            min=calculate();
        if(calculate()>max)
            max=calculate();
    }
    else
    {
        for(int i=0; i<4; i++)
        {
            if(mark[i]!=0)
            {
                arr[index]=i;
                mark[i]--;
                backtracking(index+1);
                arr[index]=0;
                mark[i]++;
            }
        }
    }

}

int main(void)
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &num[i]);
    for(int i=0; i<4; i++)
        scanf("%d", &mark[i]);
    
    backtracking(0);

    printf("%d %d", max, min);
}