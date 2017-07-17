#include <stdio.h>
#include <string.h>

int travel(char *, char *);

int main(int argc, char const *argv[])
{
	char father[1000];
	char mother[1000];
	int t = 0;

	while (1)
	{
		t++;

		fgets(father, 102, stdin);
		if (father[0] == '#') break;
		fgets(mother, 102, stdin);
		father[strlen(father)-1] = '\0';
		mother[strlen(mother)-1] = '\0';

		int i, best = -1;
		for (i = 0; i < strlen(father); i++) {
			int aux = travel(&father[i], mother);
			if (aux > best) {
				best = aux;
			}
		}

		printf("Case #%d: you can visit at most %d cities.\n", t, best);
	}
	return 0;
}

int travel(char *father, char *mother)
{
	int fidx, best = 0;

	char *mp = strchr(mother, father[0]);
	if (mp == NULL)
	{
		return best;
	}

	for (fidx = 0; fidx < strlen(father); fidx++)
	{
		int aux = travel(&father[fidx], mp+1);
		if (aux > best)
			best = aux;
	}

	return best+1;
}
