/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:52:00 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/19 19:12:00 by hakoghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	validation(char *str)
{
	int	i;

	i = 0;
	if (len(str) == 31)
	{
		while (i < 32)
		{
			if ((str[i] >= '1' && str[i] <= '4')
				&& (str[i + 1] == ' ' || str[i + 1] == '\0'))
				i += 2;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
