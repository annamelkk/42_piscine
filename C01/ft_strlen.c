#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while ( str[i] != '\0')
	i++;
	return (i);

}

int main()
{
	char c[10] = "bonjornp";
	ft_strlen(c);
		
	printf("%d", ft_strlen(c) );
	
	return (0);
}

