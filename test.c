    #include<stdio.h>
    #include<stdlib.h>
    int count =0;
    int arr[15] ={0,};

    int possible(int i, int depth)
    {
        for(int j=0; j<depth; j++)
        { // j, arr[j] / depth, i
            if(arr[j]==i || abs(j-depth) == abs(arr[j]-i))
                return 0;
        }
        return 1;
    }

    int queen(int size, int depth)
    {
        if(size==depth)
            count++;
        else
            for(int i=0; i<size; i++)
            {
                if(possible(i, depth))
                {
                    arr[depth]=i;
                    queen(size, depth+1);
                    arr[depth]=0;
                }
            }
    } //test

    int main(void)
    {
        int size;
        scanf("%d", &size);
        queen(size, 0);
        printf("%d", count);
    }