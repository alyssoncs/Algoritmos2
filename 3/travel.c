#include <stdio.h>
#include <string.h>

int travel(char *, char *);

int main(int argc, char const *argv[])
{
	char father[1000];
	char mother[1000];
	int t = 0;

	//scanf("%d", &t);
	//getchar();
	while (1)
	{
		t++;

		fgets(father, 101, stdin);
		if (father[0] == '#') break;
		fgets(mother, 101, stdin);
		father[strlen(father)-1] = '\0';
		mother[strlen(mother)-1] = '\0';
		int best = travel(father, mother);

		printf("Case #%d: you can visit at most %d cities.\n", t, best);
	}
	return 0;
}

int travel(char *father, char *mother)
{
	int best = 0;
	int fidx;

	char *mp = strchr(mother, father[0]);
	if (mp == NULL)
	{
		//printf ("entrou nessa bosta\nmother = \"%s\"\nfather[0] = '%c'\n", mother, father[0]);
		return best;
	}

	for (fidx = 0; fidx < strlen(father); fidx++) {
		int aux = travel(&father[fidx], mp+1/*&mother[mp-mother+1]*/);
		if (aux > best)
			best = aux;

	}

	/*int aux = travel(father, mp+1);
	if (aux > best)
		best = aux;*/

	return best+1;
}
