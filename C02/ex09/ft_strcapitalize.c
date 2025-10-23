/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:49:31 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/19 11:15:45 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	numerical(char c)
{
	return (c >= '0' && c <= '9');
}

int	uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if (new_word && lowercase(str[i]))
		{
			str[i] -= 32;
			new_word = 0;
		}
		else if (new_word && uppercase(str[i]))
			new_word = 0;
		else if (!new_word && uppercase(str[i]))
			str[i] += 32;
		else if ((!new_word && (lowercase(str[i]) || numerical(str[i]))))
		{
		}
		else
			new_word = 1;
		i++;
	}
	return (str);
}
/*
int main() {
    char c[] = "hi, how are you? 42words forty-two; fifty+and+one";
    ft_strcapitalize(c);
    printf("%s", c);
    return 0;
}
*/
