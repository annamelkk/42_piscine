/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:53:01 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/25 16:54:38 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	only_digits(char *str) // stugi vor menak digitner en
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

int	is_valid(char *str)
{
	if (!str || str[0] == '\0')
		return (0);
	if (!only_digits(str))
		return (0);
	return (1);
}


int	print_error(char *type)
{
	
}
