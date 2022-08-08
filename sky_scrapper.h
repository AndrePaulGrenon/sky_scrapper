#ifndef SKY_SCRAPPER
# define SKY_SCRAPPER

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
#include <sys/time.h>

typedef struct	s_data
{
	char	**info;
	int		**tab;
	int		l;
}				t_data;

int		ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_recurve_fill(t_data *data, int h, int w);
int		ft_atoi(const char *str);
void	ft_print_result(t_data *data);
int		ft_show(int a, t_data *data);
int		rules(t_data *data, int h, int w);
int		ft_init(t_data *data, char **argv);

#endif
