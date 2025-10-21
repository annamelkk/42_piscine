/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_ud_lr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoghaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:14:23 by hakoghaz          #+#    #+#             */
/*   Updated: 2025/10/19 23:02:04 by hakoghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	len(char *str);

void	rules_up_down(char *c_u, char *c_d, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (len(str) / 2))
	{
		j = 0;
		while (j < 4)
		{
			if (i >= 0 && i <= 6)
			{
				c_u[j] = str[i];
				i += 2;
				j++;
			}
			else if (i >= 8 && i <= 14)
			{
				c_d[j] = str[i];
				i += 2;
				++j;
			}
		}
	}
}

void	rules_left_right(char *r_l, char *r_r, char *str)
{
	int	i;
	int	j;

	i = 16;
	j = 0;
	while (i < len(str))
	{
		j = 0;
		while (j < 4)
		{
			if (i >= 16 && i <= 22)
			{
				r_l[j] = str[i];
				i += 2;
				++j;
			}
			else if (i >= 24 && i <= 36)
			{
				r_r[j] = str[i];
				i += 2;
				++j;
			}
		}
	}
}
