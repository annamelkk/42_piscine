/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:22:36 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/27 17:53:30 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	is_seperator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	count;
	int	i;
	
	count = 0;
	i = 0;
	while (str[i])
	{
		while (is_seperator(str[i], charset))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && !is_seperator(str[i], charset))
			i++;
	}
	return (count);
}

char	*word_dup(char *start, char *end)
{	
	int	i;
	int	length;
	char	*result;

	length = end - start;
	result = malloc(sizeof(char) * (length + 1));
	i = 0;
	while (i < length)
	{
		result[i] = start[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int	word_index;
	char	*start;
	char	*end;

	
	array = malloc(sizeof(char *) * (word_count(str, charset) + 1));
	while (*str)
	{
		while (*str && is_seperator(*str, charset)) 
			str++;
		if (*str == '\0')
			break;
		start = str;
		end = start;
		while (*end && !is_seperator(*end, charset))
			end++;
		array[word_index++] = word_dup(start, end);
		str = end;
	}
	array[word_index] = NULL;
	return (array);
}

int main(void)
{
    char str[] = "Hello,, world! This is ft_split.";
    char charset[] = " ,!."; // separators
    char **words = ft_split(str, charset);
    int i = 0;

    while (words[i])
    {
        printf("%s\n", words[i]);
        free(words[i]); // free each word
        i++;
    }
    free(words); // free the array
    return 0;
}

