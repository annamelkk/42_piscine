/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoghaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:21:09 by hakoghaz          #+#    #+#             */
/*   Updated: 2025/10/19 20:36:18 by hakoghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	col_check_up(char form[4][4], int col)
{
	char	prev;
	char	count;
	int		i;

	prev = '0';
	count = '0';
	i = 0;
	while (i < 4)
	{
		if (prev < form[i][col])
		{
			prev = form[i][col];
			++count;
			if (prev == '0' + 4)
				break ;
		}
		++i;
	}
	return (count);
}

char	col_check_down(char form[4][4], int col)
{
	char	prev;
	char	count;
	int		i;

	i = 3;
	count = '0';
	prev = '0';
	while (i >= 0)
	{
		if (prev < form[i][col])
		{
			prev = form[i][col];
			++count;
			if (prev == '0' + 4)
				break ;
		}
		--i;
	}
	return (count);
}

int	col_check(char form[4][4], int col, char col_up[4], char col_down[4])
{
	if (col_check_up(form, col) != col_up[col]
		|| col_check_down(form, col) != col_down[col])
		return (0);
	return (1);
}
