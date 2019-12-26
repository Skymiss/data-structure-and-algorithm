#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FIB_TEST	1
#define FIND_MAX_SUB_SEQUENCE	1

clock_t start, finish;
double  duration;

int fib(int n)
{
	if(n<=1)
	{
		return 1;
	}
	return fib(n-1)+fib(n-2);
}

#define algorithnm_1	0
#define algorithnm_2	0
#define algorithnm_3	1
int maxsubsequence(const int a[], int n)
{
#if algorithnm_1 == 1
	int thisum, maxsum, i, j, k;
	
	maxsum = 0;
	
	for(i = 0; i < n; i++)
	{
		for(j = i; j < n; j++)
		{
			thisum = 0;
			
			for(k = i; k <= j; k++)
			{
				thisum += a[k];
			}
			
			if(thisum >= maxsum)
			{
				maxsum = thisum;
			}
		}
	}
#endif

#if algorithnm_2 == 1
	int thisum, maxsum, i, j;

	maxsum = 0;
	for(i = 0; i < n; i++)
	{
		thisum = 0;
		for(j = i; j < n; j++)
		{
			thisum += a[j];
			if(thisum > maxsum)
			{
				maxsum = thisum;
			}
		}
	}
#endif
	
#if algorithnm_3 == 1
	int thisum, maxsum, i;
	
	thisum = maxsum = 0;
	
	for(i = 0; i < n; i++)
	{
		thisum += a[i];
		
		if(thisum > maxsum)
		{
			maxsum = thisum;
		}
		else if(thisum < 0)
		{
			thisum = 0;
		}
	}
#endif
	return maxsum;
}

int main()
{
#if FIB_TEST == 0
	
	start = clock();
	printf("%d", fib(40));
	finish = clock();
	
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	
	printf("\n");
	
	printf("%lf", duration);
#endif;

#if FIND_MAX_SUB_SEQUENCE == 1
	int a[10];
	int i, result, temp;
		
	for(i = 0; i < (sizeof(a)/sizeof(int)); i++)
	{
		temp = rand();
		a[i] = ((-1)^temp) * temp;
	}
	
	start = clock();
	result = maxsubsequence(a, 1000);
	finish = clock();
	
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	
	printf("%d \n", result);
	printf("%lf", duration);
#endif
    return 0;
}
