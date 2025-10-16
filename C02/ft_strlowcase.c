#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;
	
	i = 0;


	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	
	return (str);
}


int main()
{
	char c[] = "JeLLo";

	printf("%s", ft_strupcase(c));
	return 0;
}
