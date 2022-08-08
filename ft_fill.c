#include "sky_scrapper.h"

int ft_hard(t_data *data, int h, int w)
{

	if (h == 0 && ft_atoi(data->info[w]) == data->l && data->tab[h][w] != 1)
		return (0);
	if (h == 0 && ft_atoi(data->info[w]) == 1 && data->tab[h][w] != data->l)
		return (0);
	if (h == data->l - 1 && ft_atoi(data->info[data->l + w]) == 1 && data->tab[h][w] != data->l)
		return (0);
	if (h == data->l - 1 && ft_atoi(data->info[data->l + w]) == data->l && data->tab[h][w] != 1)
		return (0);
	if (!w && ft_atoi(data->info[(data->l * 2) + h]) == 1 && data->tab[h][w] != data->l)
		return (0);
	if (!w && ft_atoi(data->info[(data->l * 2) + h]) == data->l && data->tab[h][w] != 1)
		return (0);
	if (w == data->l - 1 && ft_atoi(data->info[(data->l * 3) + h]) == data->l && data->tab[h][w] != 1)
		return (0);
	if (w == data->l - 1 && ft_atoi(data->info[(data->l * 3) + h]) == 1 && data->tab[h][w] != data->l)
		return (0);
	return (1);
}

int ft_bro(int **tab, char **data, int h, int w)
{
	int	a;
	int	i;
	int count;
	int temp;

	temp = 0;
	count = 0;
	i = 0;
	a = ft_atoi(data[w]);
	while (tab[i][w])
	{
		if (tab[i][w] > temp)
		{
			count++;
			temp = tab[i][w];
		}
		i++;
	}
	if (count <= a)
		return (1);
	return (0);
}

int	ft_check(t_data *data, int h, int w)
{
	int 	num;
	bool	touch;
	int		i;

	num = data->tab[h][w] + 1;
	if (num > data->l)
		return (num);
	while (num < data->l + 1)
	{
		touch = false;
		i = 0;
		while (i < data->l)
		{
			if (data->tab[h][i] == num)
				touch = true;
			if (data->tab[i][w] == num)
				touch = true;
			i++;
		}
		if (!touch)
			return (num);
		num++;
	}
	return (num);
}

int	ft_recurve_fill(t_data *data, int h, int w)
{
	int		i;

	i = 1;
	if (w == data->l)
	{
		w = 0;
		h++;
	}
	if (h == data->l)
	{
		sleep(1);
		return (1);
	}
	if (!ft_bro(data->tab, data->info, h, w))
			return (ft_show(0, data));
	i = ft_check(data, h, w);
	while (i < data->l + 1)
	{
		data->tab[h][w] = i;
		if (ft_hard(data, h, w) && rules(data, h, w) && ft_recurve_fill(data, h, w + 1))
			return (1);
		i = ft_check(data, h, w);
	}
	data->tab[h][w] = 0;
	return (ft_show(0, data));
}
