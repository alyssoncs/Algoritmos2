#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define next(i, n) ((i+1)%n)

int min_swaps(int *, int);
int min_swaps_aux(int *, int *, int);
void reversearr(int *, int);

int main()
{
	int n, i;
	int aux, res;
	int aliens[500];

	while(scanf("%d", &n) && n != 0)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &aliens[i]);
			aliens[i]--;
		}
		res = min_swaps(aliens, n);
		reversearr(aliens, n);
		aux = min_swaps(aliens, n);
		res = aux<res? aux: res;
		printf("%d\n", res);
	}
	return 0;
}

void reversearr(int *arr, int n)
{
	int i, aux;

	for(i=0; i<n/2; i++)
	{
		aux = arr[i];
		arr[i] = arr[(n-1)-i];
		arr[(n-1)-i] = aux;
	}
}
int min_swaps(int *a, int n)
{
	int i, j, start;
	int count = 0, max = 0;

	/*conta a quantidade maxima de aliens no lugar certo*/
	for(i=0; i<n; i++)
	{
		for(j=i; j<n; j++)
		{
			if(a[j] == (a[i]+j-i)%n)
			{
				count++;
			}
		}
		if(count > max)
		{
			max = count;
			start = i;
		}
		count = 0;
	}

	int *vet1 = malloc(sizeof(int)*n-max);
	if(!vet1) return 0;
	int *vet2 = malloc(sizeof(int)*n-max);
	if(!vet2) return 0;

	/*coloca os errados e quem deveria estar naquela posicao
	 em vet1 e vet2 respectivamente*/
	j=0, count = 0;
	for(i=(n-a[start]+start)%n; count<n/*i!=(n-a[start]+start-1)%n*/; i=(i+1)%n, count++)
	{
		if(a[i] != (a[start]+i-start)%n)
		{
			vet1[j] = a[i];
			vet2[j] = (a[start]+i-start)%n;
			j++;
		}
	}
	return min_swaps_aux(vet1, vet2, n-max);

}


int min_swaps_aux(int *a, int *b, int n)
{
	int i, j, k;
	int pairs = 0;
	int supremo = 0;

	printf("a[] = {");
	for(j=0; j<n; j++)
		printf("%d, ", a[j]);
	printf("}\n");

	printf("b[] = {");
	for(j=0; j<n; j++)
		printf("%d, ", b[j]);
	printf("}\n");

	for(i=0; i<n; i++)
	{


		for(j=0; j<n; j++)
		{
			/*printf("testing\n\ta[%d] = %d\n\tb[%d] = %d\n", i, a[i], j, b[j]);*/
			if(a[i] == b[j]) /*se eu encontrei meu lugar*/
			{
				/*se eu estou no lugar de quem
				 esta no meu lugar*/
				if(a[j] == b[i])
				{
					pairs++;
					break;
				}
				else
				{
					for(k=0; k<n; k++)
					{
						if(a[j] == b[k] && a[k] == b[i])
						{
							supremo++;
							break;
						}
					}
				}

			}
		}

	}
	/*pairs /= 2;*/
	/*printf("n = %d\npairs = %d\n\n", n, pairs);*/
	printf("supremo = %d\n", supremo);
	supremo /= 3;
	pairs += supremo;
	if(pairs == n) return pairs /= 2;
	return n-pairs-1;
}
