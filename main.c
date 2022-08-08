#include "sky_scrapper.h"

void	ft_print_result(t_data *data)
{
	int	i;
	int j;

	printf("\nNEW ENTRY\n");
	i = 0;
	while (i < data->l)
	{
		j = 0;
		while (j < data->l)
		{
			printf("  %d", data->tab[i][j]);
			j++;
		}
		printf("  \n");
		i++;
	}	
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	data = malloc(sizeof(t_data));
	if (argv[1])
		i = ft_init(data, argv);
	if (!i)
	{
		printf("Error: Input incorrect\n");	
		return (0);
	}
	if (ft_recurve_fill(data, 0, 0))
	{
		printf("\n The Algorythm is Succesfull ! ! !\n");
		ft_print_result(data);
	}
	else 
		printf("Failed to find solution\n");
}
