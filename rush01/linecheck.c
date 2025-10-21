/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoghaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:50:30 by hakoghaz          #+#    #+#             */
/*   Updated: 2025/10/19 23:11:07 by hakoghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	line_check_left(char form[4])
{
	char	prev;
	char	count;
	int		i;

	prev = '0';
	count = '0';
	i = 0;
	while (i < 4)
	{
		if (prev < form[i])
		{
			prev = form[i];
			++count;
			if (prev == '0' + 4)
				break ;
		}
		++i;
	}
	return (count);
}

char	line_check_right(char form[4])
{
	char	prev;
	char	count;
	int		i;

	i = 3;
	count = '0';
	prev = '0';
	while (i >= 0)
	{
		if (prev < form[i])
		{
			prev = form[i];
			++count;
			if (prev == '0' + 4)
				break ;
		}
		--i;
	}
	return (count);
}

int	line_check(char form[4], int row, char row_left[4], char row_right[4])
{
	if (line_check_left(form) != row_left[row]
		|| line_check_right(form) != row_right[row])
		return (0);
	return (1);
}
