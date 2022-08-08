#include "sky_scrapper.h"

int rules_loop(t_data *data, int i, int p, int h)
{
	int count;
	int a;

	a = 0;
	count = 0;
	while (i < data->l && i >= 0)
	{
		if (a < data->tab[h][i])
		{
			a = data->tab[h][i];
			count++;
		}
		i = i + (1 * p);
		//printf("Here : %d\n",i);
	}
	return (count);
}


int rules_loop_v(t_data *data, int i, int p, int w)
{
	int count;
	int a;

	a = 0;
	count = 0;
	while (i < data->l && i >= 0)
	{
		if (a < data->tab[i][w])
		{
			a = data->tab[i][w];
			count++;
		}
		i = i + (1 * p);
		//printf("Here : %d\n",i);
	}
	return (count);
}


int rules(t_data *data, int h, int w)
{
	int	count;

	count = rules_loop(data, 0, 1, h);
	if (count > ft_atoi(data->info[(data->l * 2) + h]))
		return (0);
	if (w == data->l - 1)
	{
		count = rules_loop(data, 0, 1, h);
		if (count != ft_atoi(data->info[(data->l * 2) + h]))
			return (0);
		count = rules_loop(data, data->l - 1, -1, h);
		if (count != ft_atoi(data->info[(data->l * 3) + h]))
			return (0);
	}
	count = rules_loop_v(data, 0, 1, w);
	if (count > ft_atoi(data->info[w]))
		return (0);
	if (h == data->l - 1)
	{
		count = rules_loop_v(data, 0, 1, w);
		if (count != ft_atoi(data->info[w]))
			return (0);
		count = rules_loop_v(data, data->l - 1, -1, w);
		if (count != ft_atoi(data->info[data->l + w]))
			return (0);
	}
	return (1);
}

