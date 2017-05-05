#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*typedef enum {X_POS, X_NEG, Y_POS, Y_NEG, Z_POS, Z_NEG, NONE} direction;*/
typedef enum {X_NEG = -3, Y_NEG, Z_NEG, NONE, Z_POS, Y_POS, X_POS} direction;

void directiontostr(direction dir, char *str);
direction bender(char *str);
direction transformation(direction curDir, direction nextDir);
direction strtodirection(const char *str);

int main(int argc, char const *argv[]) {
	int L;
	char str[300005], bufferDir[3];
	direction dir;

	/*printf("{%d, %d, %d, %d, %d, %d, %d}\n", X_NEG, Y_NEG, Z_NEG, NONE, Z_POS, Y_POS, X_POS);*/
	/*printf("%s - %d\n", "+x", strtodirection("+x"));
	printf("%s - %d\n", "+y", strtodirection("+y"));
	printf("%s - %d\n", "+z", strtodirection("+z"));
	printf("%s - %d\n", "-x", strtodirection("-x"));
	printf("%s - %d\n", "-y", strtodirection("-y"));
	printf("%s - %d\n", "-z", strtodirection("-z"));*/

	while(scanf("%d", &L) && L)
	{
		getchar();
		fgets(str, 300005, stdin);
		str[strlen(str)-1] = '\0';
		dir = bender(str);
		directiontostr(dir, bufferDir);
		printf("%s\n", bufferDir);
	}
	return 0;
}

direction bender(char *str)
{
	char *token;
	direction nextDir;
	direction curDir = X_POS;

	token = strtok(str, " ");
	while(token)
	{
		nextDir = strtodirection(token);
		/*printf("[%s - %d]\n", token, nextDir);*/
		curDir = transformation(curDir, nextDir);
		token = strtok(NULL, " ");
	}
	int i;
	return curDir;

}

direction transformation(direction curDir, direction nextDir)
{
	if(nextDir == NONE)
		return curDir;
	if(curDir == X_POS)
		return nextDir;
	if(curDir == X_NEG)
		return -nextDir;
	if(curDir == Y_POS)
	{
		if(nextDir == Y_POS)
			return X_NEG;
		if(nextDir == Y_NEG)
			return X_POS;
		else return curDir;
	}
	if(curDir == Y_NEG)
	{
		if(nextDir == Y_POS)
			return X_POS;
		if(nextDir == Y_NEG)
			return X_NEG;
		else return curDir;
	}
	if(curDir == Z_POS)
	{
		if(nextDir == Z_POS)
			return X_NEG;
		if(nextDir == Z_NEG)
			return X_POS;
		else return curDir;
	}
	if(curDir == Z_NEG)
	{
		if(nextDir == Z_POS)
			return X_POS;
		if(nextDir == Z_NEG)
			return X_NEG;
		else return curDir;
	}
}

direction strtodirection(const char *str)
{
	if(!strcmp(str, "+y"))
		return Y_POS;
	if(!strcmp(str, "-y"))
		return Y_NEG;
	if(!strcmp(str, "+z"))
		return Z_POS;
	if(!strcmp(str, "-z"))
		return Z_NEG;
	return NONE;
}

void directiontostr(direction dir, char *str)
{
	if(dir < NONE)
		str[0] = '-';
	else 	str[0] = '+';

	if(dir == X_POS || dir == X_NEG)
		str[1] = 'x';
	if(dir == Y_POS || dir == Y_NEG)
		str[1] = 'y';
	if(dir == Z_POS || dir == Z_NEG)
		str[1] = 'z';
	str[2] = '\0';
}
