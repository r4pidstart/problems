#include <stdio.h>

char* itoa(int value, char* result, int base) {
		// check that the base if valid
		if (base < 2 || base > 36) { *result = '\0'; return result; }

		char* ptr = result, *ptr1 = result, tmp_char;
		int tmp_value;

		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );

		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
	}

int main(void)
{
    int num[10]={0,};
    int a,b=1,n=1;
    for(int i=0; i<3; i++)
    {
        scanf("%d", &a);
        b=a*b;
    }
    int tmp=b;
    while(tmp>10)
    {
        n++;
        tmp=tmp/10;
    }
    char s[n];
    itoa(b,s,10);
    for(int i=0; i<n; i++)
    {
        num[s[i]-48]++;
    }
    for (int i=0; i<10; i++)
    {
        printf("%d\n", num[i]);
    }
}