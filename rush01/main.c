/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:51:58 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/19 23:12:39 by hakoghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	rules_up_down(char *c_u, char *c_d, char *str);
void	rules_left_right(char *r_r, char *r_l, char *str);
int		validation(char *str);
int		len(char *str);
int		solve(char c[4][4], int pos, char rules[4][4]);

int	main(int argc, char**argv)
{
	char	c[4][4];
	char	rules[4][4];
	int		i;

	i = 0;
	if (argc == 2 && validation(argv[1]))
	{
		rules_up_down (rules[0], rules[1], argv[1]);
		rules_left_right (rules[2], rules[3], argv[1]);
		if (solve(c, 0, rules))
		{
			while (i < 16)
			{
				write(1, &c[i / 4][i % 4], 1);
				write (1, " ", 1);
				if (i++ % 4 == 3)
					write (1, "\n", 1);
			}
		}
		else
			write (1, "Error\n", 6);
	}
	else
		write (1, "Error\n", 6);
	return (0);
}
