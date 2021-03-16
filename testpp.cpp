#include<iostream>
#include<utility>

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        std::pair <std::string, std::string> equipment[n];
        for(int i=0; i<n; i++)
            scanf("%s %s", equipment[i].first, equipment[i].second);
        
    }
}
