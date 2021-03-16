#include<stdio.h>
#include<string.h>

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, class_count=0, class_i[30]={0,};
        scanf("%d", &n);
        char trash[21], tmp[21]={0,}, class[30][21]={0,};
        for(int i=0; i<n; i++)
        {
            scanf("%s %s", trash, tmp);
            for(int i=0; i<n; i++)
            {
                if(class_i[i]==0)
                {
                    strcpy(class[i], tmp);
                    class_count++;
                    class_i[i]++;
                    break;
                }
                else if(!strcmp(tmp, class[i]))
                {
                    class_i[i]++;
                    break;
                }
            }
        }
        int res=1;
        for(int i=0; i<class_count; i++)
            res*=class_i[i]+1;
        
        printf("%d\n", res-1);
    }
}