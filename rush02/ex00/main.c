/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 12:08:09 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/26 15:27:43 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

int	handle_errors(char *number, char *dict_file, t_dict **dict)
{
	if (!is_valid_number(number))
	{
		print_error("Error");
		return (1);
	}
	*dict = parse_dictionary(dict_file);
	if (!*dict || !validate_dict(*dict))
	{
		print_error("Dict Error");
		if (*dict)
			free_dict(*dict);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_dict	*dict;
	char	*dict_file;
	char	*number;

	if (argc < 2 || argc > 3)
	{
		print_error("Error");
		return (1);
	}
	if (argc == 2)
	{
		dict_file = "numbers.dict";
		number = argv[1];
	}
	else
	{
		dict_file = argv[1];
		number = argv[2];
	}
	if (handle_errors(number, dict_file, &dict))
		return (1);
	convert_number(number, dict);
	ft_putchar('\n');
	free_dict(dict);
	return (0);
}
