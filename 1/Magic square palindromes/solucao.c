/*
* Versão em C de solucao.cpp
* UVA não está aceitando
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


char *Convert(char *line)
{
	char *phrase = malloc(sizeof(char)*20000);
	if(!phrase)
		return NULL;
	
	int i, j = 0;
	for (i = 0; i < strlen(line); i++)
	{
		if (line[i] >= 'a' && line[i] <= 'z')
		{
			phrase[j] = line[i];
			j++;
		}
	}
	phrase[j] = '\0';

	return phrase;
}

int MagicBoxSize(char *phrase)
{
	int boxSize = sqrt(strlen(phrase));

	if (boxSize * boxSize != strlen(phrase))
		return 0;

	int end = strlen(phrase) - 1;
	int goTo = strlen(phrase)/2+strlen(phrase)%2;
	int start = 0;
	
	int main;
	for (main = 0; main <= goTo; main++)
	{
		if (phrase[start] != phrase[end])
		{
			return 0;
		}
		start++;;
		end--;
	}

	return boxSize;
	
}


int main(void)
{
	char entrada[14];
	char line[20000];
	char *phrase;

	int T;
	fgets(entrada, 10, stdin);
	sscanf(entrada, "%d", &T);
	int t;
	for (t = 1; t <= T; t++)
	{
		fgets(line, 20000, stdin);

		phrase = Convert(line);
		if(!phrase)
			return 0;

		printf("Case #%d:\n", t);

		int size = MagicBoxSize(phrase);

		if (size)
			printf("%d\n", size);
		else
			printf("No magic :(\n");
		
		free(phrase);
	}
	return 0;
}