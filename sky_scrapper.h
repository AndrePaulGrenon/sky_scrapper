#ifndef SKY_SCRAPPER
# define SKY_SCRAPPER

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>

int		ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_recurve_fill(int tab[4][4], int size, int h, int w, char **data);
int		ft_atoi(const char *str);
void	ft_print_result(int tab[4][4]);
int		ft_show(int a, int tab[4][4]);

#endif
