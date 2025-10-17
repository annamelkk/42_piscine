#include <stdio.h>

int	numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	is_all(char c)
{
	return (numeric(c) || lowercase(c) || uppercase(c));
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int new_word;


	i = 0;
	new_word = 1;

	while (str[i] != '\0')
	{
		if (is_all(str[i]))
		{
			if (new_word && lowercase(str[i]))
				str[i] -= 32;
			else if (!new_word && uppercase(str[i]))
				str[i] += 32;
			new_word = 0;
		}
		else
			new_word = 1;
		i++;
	}
	return (str);
}


#include <stdio.h>

int main(void)
{
    char c[] = "hi, how are you? 42words forty-two; fifty+and+one";
    
    printf("Before: %s\n", c);
    ft_strcapitalize(c);
    printf("After:  %s\n", c);
    
    return (0);
}



