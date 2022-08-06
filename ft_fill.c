#include "sky_scrapper.h"

int ft_hard(int tab[4][4], char **data, int h, int w)
{

	if (h == 0 && ft_atoi(data[w]) == 4 && tab[h][w] != 1)
		return (0);
	if (h == 0 && ft_atoi(data[w]) == 1 && tab[h][w] != 4)
		return (0);
	if (h == 3 && ft_atoi(data[4 + w]) == 1 && tab[h][w] != 4)
		return (0);
	if (h == 3 && ft_atoi(data[4 + w]) == 4 && tab[h][w] != 1)
		return (0);
	if (!w && ft_atoi(data[8 + h]) == 1 && tab[h][w] != 4)
		return (0);
	if (!w && ft_atoi(data[8 + h]) == 4 && tab[h][w] != 1)
		return (0);
	if (w == 3 && ft_atoi(data[12 + h]) == 4 && tab[h][w] != 1)
		return (0);
	if (w == 3 && ft_atoi(data[12 + h]) == 1 && tab[h][w] != 4)
		return (0);
	return (1);
}

int ft_bro(int tab[4][4], char **data, int h, int w)
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

int	ft_check(int tab[4][4], char **data, int h, int w)
{
	int 	num;
	bool	touch;
	int		i;

	num = tab[h][w] + 1;
	if (num > 4)
		return (num);
	while (num < 5)
	{
		touch = false;
		i = 0;
		while (i < 4)
		{
			if (tab[h][i] == num)
				touch = true;
			if (tab[i][w] == num)
				touch = true;
			i++;
		}
		if (!touch)
			return (num);
		num++;
	}
	(void) data;
	return (num);

}

int	ft_recurve_fill(int tab[4][4], int size, int h, int w, char **data)
{
	int		i;

	i = 1;
	if (w == size)
	{
		w = 0;
		h++;
	}
	if (h == size)
	{
		sleep(1);
		return (1);
	}
	if (!ft_bro(tab, data, h, w))
			return (ft_show(0, tab));
	i = ft_check(tab, data, h, w);
	while (i < 5)
	{
		tab[h][w] = i;
		if (ft_hard(tab, data, h, w) && rules(tab, data, h, w) && ft_recurve_fill(tab, size, h, w + 1, data))
			return (1);
		i = ft_check(tab, data, h, w);
	}
	tab[h][w] = 0;
	return (ft_show(0, tab));
}
