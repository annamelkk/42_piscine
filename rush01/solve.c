/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoghaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:58:30 by hakoghaz          #+#    #+#             */
/*   Updated: 2025/10/19 20:43:42 by hakoghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	not_rpt(char form[4][4], int pos, char num);
int	line_check(char form[4], int row, char row_left[4], char row_right[4]);
int	col_check(char form[4][4], int col, char col_up[4], char col_down[4]);

int	solve(char c[4][4], int pos, char rules[4][4])
{
	char	i;

	if (pos == 16)
		return (1);
	i = '0';
	while (i <= '4')
	{
		++i;
		c [pos / 4][pos % 4] = i;
		if (not_rpt (c, pos, c[pos / 4][pos % 4]))
			if (pos % 4 != 3
				|| line_check (c[pos / 4], (pos / 4), rules[2], rules[3]))
				if (pos / 4 != 3 || col_check (c, pos % 4, rules[0], rules[1]))
					if (solve(c, pos + 1, rules))
						return (1);
	}
	return (0);
}
