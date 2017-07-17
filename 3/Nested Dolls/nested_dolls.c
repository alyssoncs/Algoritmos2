#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct
{
	int w, h;
} doll;

int *memo;

int inner_doll(doll *dolls, int n, int *set);
int fits(doll *out, doll *inner);

int *create_set(size_t n);
void destroy_set(int *set);
void reset_set(int *set, int n);
int dj_set(int *set, int s1);
void dj_union(int *set, int s1, int s2);

int cmp(const void *a1, const void *a2) /* reverse comparison function */
{
	doll *a = (doll *)a1;
	doll *b = (doll *)a2;

	if (a->w == b->w && a->h == a->h)
		return 0;
	if (a->w > b->w || a->w == b->w && a->h > b->h)
		return -1;
	return 1;

}


int main(void)
{
	int t;

	scanf("%d", &t);
	while (t--)
	{
		int m;
		scanf("%d", &m);

		int *set 	= create_set(m);
		doll *dolls 	= (doll *)malloc(sizeof(doll)*m);
		memo 		= (int *)calloc(m, sizeof(int));
		if (set && dolls && memo)
		{
			int i;
			for (i = 0; i < m; i++)
			{
				scanf("%d %d", &dolls[i].w, &dolls[i].h);
			}
			qsort(dolls, m, sizeof(doll), cmp);

			int count = 0;
			int dolls_left = m;
			while (dolls_left) /* enquanto existir boneca */
			{
				int d = inner_doll(dolls, dolls_left, set);

				/* exclui bonecas */
				for (i = 0; i < dolls_left; i++)
				{
					if (dj_set(set, i) == dj_set(set, d))
					{
						dolls[i].w = INT_MAX;
						dolls[i].h = INT_MAX;
					}
				}
				qsort(dolls, dolls_left, sizeof(doll), cmp);
				reset_set(set, m);
				dolls_left -= memo[d];

				memset(memo, 0, sizeof(int)*dolls_left);

				count++;
			}
			printf("%d\n", count);
		}
		destroy_set(set);
		free(dolls);
		free(memo);
	}
	return 0;
}

int inner_doll(doll *dolls, int n, int *set)
{
	int max_doll = 0;
	int i, j, aux_i = 0;
	for (i = 0; i < n; i++)
	{
		int max = 0, aux_j = 0;
		for (j = i-1; j >= 0; j--)
		{
			if (fits(&dolls[j], &dolls[i]))
			{
				int aux = memo[j];
				if (aux > max)
					max = aux, aux_j = j;
			}
		}
		memo[i] = max+1;
		dj_union(set, i, aux_j);

		if (memo[i] > max_doll)
			max_doll = memo[i], aux_i = i;
	}
	return aux_i;
}

int fits(doll *out, doll *inner)
{
	if (out && inner)
		if ((out->w > inner->w) && (out->h > inner->h))
			return 1;
	return 0;
}


int *create_set(size_t n)
{
	int *set = (int *)malloc(sizeof(int)*n);

	if (set)
	{
		int i;
		for (i = 0; i < n; i++)
			set[i] = i;
	}
	return set;

}

void destroy_set(int *set)
{
	free(set);
}

void reset_set(int *set, int n)
{
	int i;
	for (i = 0; i < n; i++)
		set[i] = i;
}

int dj_set(int *set, int s1)
{
	if (set[s1] == s1)
		return s1;
	else
		return set[s1] = dj_set(set, set[s1]);
}

void dj_union(int *set, int s1, int s2)
{
	set[dj_set(set, s1)] = dj_set(set, s2);
}
