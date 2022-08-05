#include "sky_scrapper.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return ;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, size * count);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	i = start;
	if (start >= (ft_strlen(s)))
		return (str);
	while (s[i] && j < len)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	return (str);
}

static	unsigned int	ft_strdiv(const char *s, char c)
{
	int		i;
	int		count;
	bool	div;

	div = true;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			div = true;
		else
		{
			if (div == true)
				count++;
			div = false;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	int				count;
	int				start;

	if (!s)
		return (0);
	tab = ft_calloc(ft_strdiv(s, c) + 1, sizeof(char *));
	if (!tab)
		return (0);
	count = 0;
	start = -1;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start == -1)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			tab[count++] = ft_substr(s, start, (i - start));
			start = -1;
		}
		i++;
	}
	return (tab);
}
