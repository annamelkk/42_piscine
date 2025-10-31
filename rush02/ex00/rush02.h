/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:24:14 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/26 15:25:39 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict_entry
{
	char	*key;
	char	*value;
}	t_dict_entry;

typedef struct s_dict
{
	t_dict_entry	*entries;
	int				size;
	int				capacity;
}	t_dict;

// utils1.c
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
void	ft_putchar(char c);

// utils2.c
int		ft_isspace(char c);
char	*ft_strtrim(char *str);
int		ft_atoi(char *str);
int		ft_atoi_n(char *str, int n);
char	*read_line(int fd);

// validator.c
int		has_only_digits(char *str);
int		is_valid_number(char *str);
void	print_error(char *type);

// parser.c
t_dict	*init_dict(void);
int		add_entry(t_dict *dict, char *key, char *value);
int		parse_line(char *line, t_dict *dict);
t_dict	*parse_dictionary(char *filename);
void	free_dict(t_dict *dict);

// lookup.c
char	*dict_lookup(t_dict *dict, char *key);
int		has_key(t_dict *dict, char *key);
int		validate_dict(t_dict *dict);

// converter.c
void	ft_put_digit(int n, t_dict *dict);
void	ft_put_ten(int n, t_dict *dict);
void	ft_put_twenty(int n, t_dict *dict);
void	ft_put_hundred(int n, t_dict *dict);
void	convert_number(char *num, t_dict *dict);

#endif
