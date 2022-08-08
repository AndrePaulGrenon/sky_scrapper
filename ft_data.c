#include "sky_scrapper.h"

void	tab_zero(int **tab, int size)
	{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			tab[i][j] = 0;
			j++;
		}
 		i++;
 	}
 }

int	tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	if (i == 16)
		return (4);
	if (i == 20)
		return (5);
	if (i == 24)
		return (6);
	if (i == 28)
		return (7);
	if (i == 32)
		return (8);
	if (i == 36)
		return (9);
	printf("%d\n", i);
	return (0);
}

void	ft_free_tab(char **info)
{
	int	i;

	i = 0;
	while (info[i])
	{
		free(info[i]);
		i++;
	}
	free(info);
}

int	**ft_create_tab(int size)
{
	int	i;
	int	j;
	int **tab;

	tab = malloc(sizeof(int *) * size);
	i = 0;
	while (i < size)
	{
		tab[i] = malloc(sizeof(int) * size);
		i++;
	}
	tab_zero(tab, size);
	return (tab);
}

int	ft_init(t_data *data, char **argv)
{
	int	i;

	data->info = ft_split(argv[1], 32);
	data->l = tab_size(data->info);
	if (data->l == 0)
	{
		ft_free_tab(data->info);
		free(data);
		return (0);
	}
	data->tab = ft_create_tab(data->l);
	return (data->l);
}

