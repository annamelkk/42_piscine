/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:41:56 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/26 15:31:17 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_put_digit(int n, t_dict *dict)
{
	char	key[2];

	key[0] = '0' + n;
	key[1] = '\0';
	ft_putstr(dict_lookup(dict, key));
}

void	ft_put_ten(int n, t_dict *dict)
{
	char	key[3];

	key[0] = '1';
	key[1] = '0' + (n % 10);
	key[2] = '\0';
	ft_putstr(dict_lookup(dict, key));
}

void	ft_put_twenty(int n, t_dict *dict)
{
	char	key[3];
	int		tens;
	int		ones;

	if (n < 20)
	{
		if (n < 10)
			ft_put_digit(n, dict);
		else
			ft_put_ten(n, dict);
		return ;
	}
	tens = (n / 10) * 10;
	ones = n % 10;
	key[0] = '0' + (tens / 10);
	key[1] = '0';
	key[2] = '\0';
	ft_putstr(dict_lookup(dict, key));
	if (ones != 0)
	{
		ft_putstr(" ");
		ft_put_digit(ones, dict);
	}
}

void	ft_put_hundred(int n, t_dict *dict)
{
	int	hundreds;
	int	remainder;

	if (n >= 100)
	{
		hundreds = n / 100;
		ft_put_digit(hundreds, dict);
		ft_putstr(" ");
		ft_putstr(dict_lookup(dict, "100"));
		remainder = n % 100;
		if (remainder != 0)
		{
			ft_putstr(" ");
			ft_put_twenty(remainder, dict);
		}
	}
	else
		ft_put_twenty(n, dict);
}

void	convert_number(char *num, t_dict *dict)
{
	int	val;

	if (ft_strcmp(num, "0") == 0)
	{
		ft_putstr(dict_lookup(dict, "0"));
		return ;
	}
	if (ft_strlen(num) <= 3)
	{
		ft_put_hundred(ft_atoi(num), dict);
	}
	else if (ft_strlen(num) <= 6)
	{
		val = ft_atoi_n(num, ft_strlen(num) - 3);
		ft_put_hundred(val, dict);
		ft_putstr(" ");
		ft_putstr(dict_lookup(dict, "1000"));
		val = ft_atoi(&num[ft_strlen(num) - 3]);
		if (val != 0)
		{
			ft_putstr(" ");
			ft_put_hundred(val, dict);
		}
	}
}
