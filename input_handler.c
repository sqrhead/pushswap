#include "push_swap.h"

int	ft_isdigit(char c)
{
	if (c <= '9' && c >= '0')
		return (0);
	return (1);
}

int ft_isspace(char c)
{
	if (c == ' ' || c >= 9 && c <= 13)
		return (0);
	return (1);
}

int ft_issign(char c)
{
	if (c == '-' || c == '+')
		return (0);
	return (1);
}

int	is_input_valid(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (1);
	while (str[index])
	{
		while (ft_isspace(str[index]) == 0)
			index ++;
		if (ft_issign(str[index]) == 0 && str[index + 1] && ft_isdigit(str[index + 1]) == 0)
			index ++;
		if (str[index] && ft_isdigit(str[index]) == 1)
			return (1);
		while(ft_isdigit(str[index]) == 0)
			index ++;
		if (str[index] && ft_isspace(str[index]) == 1)
			return(1);
	}
	return (0);
}

int	check_input(char *str)
{
	if (is_input_valid(str) == 1)
	{
		write(1,"Error\n",ft_strlen("Error\n"));
		return (1);
	}

}