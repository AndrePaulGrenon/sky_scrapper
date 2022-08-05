#include "sky_scrapper.h"

void	ft_print_result(int tab[4][4])
{
	int	i;
	int j;

	printf("\nNEW ENTRY\n");
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("  %d", tab[i][j]);
			j++;
		}
		printf("  \n");
		i++;
	}	
}

void	tab_zero(int tab[4][4], int size)
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

int	main(int argc, char **argv)
{
	char	**data;
	int		tab[4][4];
	int		i;

	tab_zero(tab, 4);
	if (argv[1])
	{
		i = 0;
		data = ft_split(argv[1], 32); 
		while (data && data[i])
		{
			printf("data[%d]: %s\n", i, data[i]);
			i++;
		}
	}
	if (ft_recurve_fill(tab, 4, 0, 0, data))
	{
		printf("\n The Algorythm is Succesfull ! ! !\n");
		ft_print_result(tab);
	}
	else 
		printf("Failed to find solution\n");
}
