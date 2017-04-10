/*
* Autor: Alysson Cirilo Silva
* UVA não está aceitando
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>


int is_magic_square(char *str, int N);
int main(void)
{
	double root;
	int t, i, j, tam, K, ans;
	char str1[10002], str2[10002];
	char entrada[14];
	
	fgets(entrada, 10, stdin);
	sscanf(entrada, "%d", &t);
	for(j=0; j<t; j++)
	{
		fgets(str1, 10002, stdin);
		tam = 0;
		for(i=0; str1[i] != '\0'; i++)
		{
			if(isalpha(str1[i]))
			/*if (str1[i] >= 'a' && str1[i] <= 'z')*/
			{
				str2[tam] = str1[i];
				tam++;
			}
		}
		str2[tam] = '\0';
		
		root = sqrt(tam);
		K = (int)root;
		
		ans = is_magic_square(str2, K);			
		
		printf("Case #%d:\n", j+1);
		if(ans)
			printf("%d\n", K);
		else
			printf("No magic :(\n");
		
	}
	return 0;
}



int is_magic_square(char *str, int N)
{
	int i;
	int ltr, rtl, topDown, bottomUp;
		
	ltr = topDown = 0;
	rtl = bottomUp = N*N-1;
	
	if(N*N != strlen(str))
		return 0;
	
	for(i=0; i<(N*N)/2+(N*N)%2; i++)
	{
		if((str[ltr] != str[rtl] || str[ltr] != str[topDown] || str[ltr] != str[bottomUp]))
		{
			return 0;
		}
		
		ltr++;
		rtl--;
		topDown = (topDown >= N*(N-1)) ? topDown%N+1 : topDown+N;
		bottomUp = (bottomUp <= N-1) ? bottomUp+N*(N-1)-1 : bottomUp-N;
		
	}
	
	
	return 1;
}












