#include <stdio.h>

int	ft_atoi(char *str)
{
	int	sign;
	long long	result;
	int	i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;		
	}

	if (result > 2147483647 && sign == 1)
		return (2147483647);
	if (result > 2147483648LL && sign == -1)
		return (-2147483648);
	return (int)(result * sign);
}


int main()
{
	char c[] = "--+-+214748348";

	printf("%d", ft_atoi(c));
	return (0);
}
