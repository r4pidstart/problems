#include<stdio.h>
#include<stdlib.h>

// time exceeded
int n,max_w, *weigh, *value, tmp_w=0, max_v=0, tmp_v=0;

int dfs(int index)
{
    if(n==index)
    {
        if(max_v<tmp_v)
            max_v=tmp_v;
    }
    else
        for(int i=index; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(tmp_w+weigh[j]>=max_w)
                {
                        if(tmp_w+weigh[j]==max_w)
                        {
                            if(max_v<tmp_v+value[j])
                                max_v=tmp_v+value[j];
                        }
                        else
                            if(max_v<tmp_v)
                                max_v=tmp_v;
                }
                else
                {
                tmp_w+=weigh[j];
                tmp_v+=value[j];
                dfs(index+1);
                tmp_w-=weigh[j];
                tmp_v-=value[j];
                }
}

int main(void)
{
    scanf("%d %d", &n, &max_w);
    weigh=malloc(sizeof(int)*n+1);
    value=malloc(sizeof(int)*n+1);
    for(int i=0; i<n; i++)
        scanf("%d %d", &weigh[i], &value[i]);
    
    dfs(0);

    printf("%d", max_v);
}