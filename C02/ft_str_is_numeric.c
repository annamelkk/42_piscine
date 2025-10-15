#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int i;

	i = 0;

	if (str[0] == '\0')
		return 1;

	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '1')))
		{		
			return (0);
		}
		i++;
	}

	return (1);
}


int main()
{
    printf("%d\n", ft_str_is_alpha("hello"));   
    return 0;
}
