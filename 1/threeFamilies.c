#include <stdio.h>

int main(void)
{
	int t, i;
	int x, y, z;
	double each;
	
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		
		each = (x+y)/3.0;
		
		/*if(x <= each)
		{
			printf("0\n");
		}
		else if(x >= 2*each)
		{
			printf("%d\n", z);
		}
		else
		{
			printf("%.0lf\n", ((double)z * ((double)x-each) / each));
		}*/
		printf("%.0lf\n", ((double)z * ((double)x-each) / each));
		
	}
	return 0;
}