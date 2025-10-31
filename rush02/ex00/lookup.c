/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 10:17:37 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/26 11:44:15 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*dict_lookup(t_dict *dict, char *key)
{
	int	i;

	if (!dict || !key)
		return (NULL);
	i = 0;
	while (i < dict->size)
	{
		if (ft_strcmp(dict->entries[i].key, key) == 0)
			return (dict->entries[i].value);
		i++;
	}
	return (NULL);
}

int	has_key(t_dict *dict, char *key)
{
	if (dict_lookup(dict, key))
		return (1);
	return (0);
}

int	validate_dict(t_dict *dict)
{
	if (!has_key(dict, "0"))
		return (0);
	if (!has_key(dict, "1"))
		return (0);
	if (!has_key(dict, "10"))
		return (0);
	if (!has_key(dict, "20"))
		return (0);
	if (!has_key(dict, "100"))
		return (0);
	if (!has_key(dict, "1000"))
		return (0);
	if (!has_key(dict, "1000000"))
		return (0);
	if (!has_key(dict, "1000000000"))
		return (0);
	if (!has_key(dict, "1000000000000"))
		return (0);
	if (!has_key(dict, "1000000000000000"))
		return (0);
	if (!has_key(dict, "1000000000000000000"))
		return (0);
	return (1);
}
