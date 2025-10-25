#ifndef RUSH02_H_
#define RUSH02_H_

#include <unistd.h>
#include <stdlib.h>
#include <sys/fcntl.h>
//dict entry
typedef struct	s_dict_entry
{
	char	*key; // "42"
	char	*value // "forty two"
}	t_dict_netry;
//dict
typedef struct	s_dict
{
	t_dict_entry	*entries;
	int	size;
	int	capacity;
}	t_dict;

// utils1 
void	ft_putchar(char *str);
void	ft_putstr(char *str);
char	*ft_strdup(char *src);
int	ft_strcmp(char *s1, char *s2);
int	ft_strlen(char *str);
//utils2
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char str);
char	**fr_split(char *str, char delimeter);
//validator
int	only_digits(char *str);
int	is_valid(char *str);
// converter
char	*convert_number(char *number, t_dict *dict); // for single number
char	*convert_chunk(char *chunk, t_dict *dict); // for 3 digit groups
char	*convert_two_digits(char *num, t_dict *dict); // for 2 digits
// parser
#endif
