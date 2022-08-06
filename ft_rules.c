#include "sky_scrapper.h"


int rules_loop(int tab[4][4], int i, int p, int h)
{
	int count;
	int a;

	a = 0;
	count = 0;
	while (i < 4 && i >= 0)
	{
		if (a < tab[h][i])
		{
			a = tab[h][i];
			count++;
		}
		i = i + (1 * p);
		//printf("Here : %d\n",i);
	}
	return (count);
}


int rules_loop_v(int tab[4][4], int i, int p, int w)
{
	int count;
	int a;

	a = 0;
	count = 0;
	while (i < 4 && i >= 0)
	{
		if (a < tab[i][w])
		{
			a = tab[i][w];
			count++;
		}
		i = i + (1 * p);
		//printf("Here : %d\n",i);
	}
	return (count);
}

int rules(int tab[4][4], char **data, int h, int w)
{
	int	count;
	
	if (w == 3)
	{
		count = rules_loop(tab, 0, 1, h);
		if (count != ft_atoi(data[8 + h]))
			return (0);
		count = rules_loop(tab, 3, -1, h);
		if (count != ft_atoi(data[12 + h]))
			return (0);
	}
	if (h == 3)
	{
		count = rules_loop_v(tab, 0, 1, w);
		if (count != ft_atoi(data[w]))
			return (0);
		count = rules_loop_v(tab, 3, -1, w);
		if (count != ft_atoi(data[4 + w]))
			return (0);

	}

	return (1);
}

