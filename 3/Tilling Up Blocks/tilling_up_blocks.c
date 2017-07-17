#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int l, m;
} block;

int *TOWER;

int max(block *b)
{
	return (b->l > b->m) ? b->l : b->m;
}

int min(block *b)
{
	return (b->l < b->m) ? b->l : b->m;
}

int fits(block *bottom, block *top)
{
	if (bottom && top)
		if ((top->l >= bottom->l) && (top->m >= bottom->m))
			return 1;
	return 0;
}


int cmp2(const void *a, const void *b)
{
	block *b1 = (void*)a;
	block *b2 = (void*)b;


	if (b1->l == b2->l && b1->m == b2->m)
		return 0;
	if (b1->l < b2->l || b1->l == b2->l && b1->m < b2->m)
		return -1;
	return 1;
}

int cmp(const void *a, const void *b)
{
	block *b1 = (void*)a;
	block *b2 = (void*)b;

	if (b1->l == b2->l && b1->m == b2->m)
		return 0;
	if (!fits(b2, b1))
		return -1;
	return 1;
}
/*
   int max_tower(block blocks[], int n, int idx)
   {
        if (idx == n-1)
                return 1;
        if (TOWER[idx])
                return TOWER[idx];

        int i;
        for (i = idx+1; i < n && !fits(&blocks[idx], &blocks[i]); i++) {};
        int i = 0;
        int max = 0;
        if (i != idx && fits(&blocks[idx], &blocks[i]))
                max = TOWER[i] = max_tower(blocks, n, i);
        for (i = 1; i < n; i++)
        {
                if (i != idx && fits(&blocks[idx], &blocks[i]))
                {
                        int tmp = TOWER[i] = max_tower(blocks, n, i);
                        if (tmp > max)
                                max = tmp;
                }
        }
        return max+1;
   }
 */

int max_tower(block blocks[], int n, int idx)
{
	if (TOWER[idx])
		return TOWER[idx];
	/*int max = TOWER[i] = max_tower(blocks, n, i);*/
	int i;
	int max = TOWER[idx];
	for (i = idx - 1; i >= 0; i--)
	{
		if (fits(&blocks[i], &blocks[idx]))
		{
			int tmp = max_tower(blocks, n, i);
			if (tmp > max)
				max = tmp;
		}
	}
	return TOWER[idx] = max + 1;
}

int main(void)
{
	int n;

	while (scanf("%d", &n) && n)
	{
		block *blocks   = (block*)malloc(sizeof(block) * n);
		TOWER           = (int*)calloc(n, sizeof(int));
		if (blocks && TOWER)
		{
			int i;
			for (i = 0; i < n; i++)
				scanf("%d %d", &blocks[i].l, &blocks[i].m);
			qsort(blocks, n, sizeof(blocks), cmp2);
		}


		/*int i;
		   for (i = 0; i < n; i++)
		        if (!fits(&blocks[n-1], &blocks[i]))
		                printf("DON'T FITS\t(%d, %d)(%d, %d)\n",
		                        blocks[n-1].l, blocks[n-1].m,
		                        blocks[i].l, blocks[i].m);
		        else    printf("FITS!\t\t(%d, %d)(%d, %d)\n",
		                        blocks[n-1].l, blocks[n-1].m,
		                        blocks[i].l, blocks[i].m);*/


		/* pode ser que eu tenha que fazer um loop aqui,
		 * para encontrar o maior de todos mesmo
		 */
		int i, max = 0, aux;
		for (i = 0; i < n; i++)
		{
			aux = max_tower(blocks, n, i);
			if (aux > max)
				max = aux;
		}

		/*printf("%d\n", TOWER[n-1]);*/
		printf("%d\n", max);
		free(blocks);
		free(TOWER);
	}
	printf("*\n");

	return 0;
}
