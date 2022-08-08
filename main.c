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
	struct timeval time;
	long int ms;

	gettimeofday(&time, NULL);
	ms = time.tv_sec * 1000 + (long int) time.tv_usec / 1000;
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
	gettimeofday(&time, NULL);
	printf("\nProgram total time: %ld ms\n", (time.tv_sec * 1000 + (long int) time.tv_usec / 1000) - ms);
}
