/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:53:01 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/26 12:16:27 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	has_only_digits(char *str) // stugi vor menak digitner en
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_number(char *str)
{
	if (!str || str[0] == '\0')
		return (0);
	if (!has_only_digits(str))
		return (0);
	return (1);
}

void	print_error(char *type)
{
	ft_putstr(type);
	ft_putchar('\n');
}
