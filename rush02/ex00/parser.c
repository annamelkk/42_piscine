/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 10:18:08 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/26 15:17:54 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_dict	*init_dict(void)
{
	t_dict	*dict;

	dict = malloc(sizeof(t_dict));
	if (!dict)
		return (NULL);
	dict->entries = malloc(sizeof(t_dict_entry) * 50);
	if (!dict->entries)
	{
		free(dict);
		return (NULL);
	}
	dict->size = 0;
	dict->capacity = 50;
	return (dict);
}

int	add_entry(t_dict *dict, char *key, char *value)
{
	if (dict->size >= dict->capacity)
		return (0);
	dict->entries[dict->size].key = key;
	dict->entries[dict->size].value = value;
	dict->size++;
	return (1);
}

int	parse_line(char *line, t_dict *dict)
{
	int		i;
	char	*key;
	char	*value;

	if (!line || line[0] == '\n' || line[0] == '\0')
		return (1);
	i = 0;
	while (line[i] && line[i] != ':')
		i++;
	if (line[i] != ':')
		return (0);
	line[i] = '\0';
	key = ft_strtrim(line);
	value = ft_strtrim(&line[i + 1]);
	line[i] = ':';
	if (!key || !value)
		return (0);
	return (add_entry(dict, key, value));
}

void	free_dict(t_dict *dict)
{
	int	i;

	if (!dict)
		return ;
	i = 0;
	while (i < dict->size)
	{
		free(dict->entries[i].key);
		free(dict->entries[i].value);
		i++;
	}
	free(dict->entries);
	free(dict);
}

t_dict	*parse_dictionary(char *filename)
{
	t_dict	*dict;
	int		fd;
	char	*line;

	dict = init_dict();
	if (!dict)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free_dict(dict);
		return (NULL);
	}
	line = read_line(fd);
	while (line)
	{
		if (!parse_line(line, dict))
			return (free(line), close(fd), free_dict(dict), NULL);
		free(line);
		line = read_line(fd);
	}
	close(fd);
	return (dict);
}
