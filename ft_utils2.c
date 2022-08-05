#include "sky_scrapper.h"

int	ft_show(int a, int tab[4][4])
{

	ft_print_result(tab);
	usleep(350000);
	if (a == 1)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	res;
	long long	neg;

	neg = 1;
	res = 0;
	i = 0;
	while (str[i] == 32 || (str[i] < 14 && str[i] > 8))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			neg = neg * (-1);
		i++;
	}
	while (str[i] < 58 && str[i] > 47)
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * neg);
}
