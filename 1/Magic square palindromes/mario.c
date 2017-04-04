#include <stdio.h>

int main(void)
{
	int t, n, i, j;
	int highJumps, lowJumps;
	int wall[49];
	
	scanf("%d", &t);
	
	for(i=0; i<t; i++)
	{
		highJumps = lowJumps = 0;
		
		scanf("%d", &n);
		for(j=0; j<n; j++)
		{
			scanf("%d", &wall[j]);
		}
		for(j=0; j<n-1; j++)
		{
			if(wall[j] < wall[j+1])
				highJumps++;
			if(wall[j] > wall[j+1])
				lowJumps++;
		}
		printf("Case %d: %d %d\n", i+1, highJumps, lowJumps);
	}
	return 0;
}