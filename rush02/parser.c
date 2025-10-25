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
	int	i;
	char	*key;
	char	*value;
	
	if (!line || line[0] == '\n' || line[0] == '\0')
		rturn (1);
	i = 0;
	while (line[i] && line[i] != ':')
		i++;
	if (line[i] != ':')
		return (0);
	line[i] = '\0';
	key = ft_strtrim(line);
	value = ft_strtrim(&line[i+1]);
	line[i] = ':';
	if (!key || !value)
		return (0);
	return (add_entry(dict, key, value))
}


int	*read_line(int fd)
{
	char	buffer[1000];
	int	i;
	int	ret;
	
	i = 0;
	while ((ret = read(fd, &buffer[i], 1)) > 0)
	{
		if (buffer[i] == '\n')
		{
			buffer[i + 1] = '\0';
			return (ft_strdup(buffer));	
		}
	i++;
	}
	if (i > 0)
	{
		buffer[i] = '\0';
		return (ft_strdup(buffer));
	}
	return (NULL);
}


t_dict	*parse_dictionary(char *filename)
{
	int	fd;
	int	*line;
	t_dict	*dict;

	dict = init_dict();
	if (!dict)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free_dict(dict);
		return (NULL);
	}
	while (line = read_line(fd))
	{
		if(!parse_line(line, dict))
		{
			free(line);
			free(fd);
			free_dict(dict);
			return (NULL);
		}
		free(line);
	}
	close(fd);
	return (dict);
}
