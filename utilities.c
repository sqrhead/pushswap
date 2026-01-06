#include "push_swap.h"

int ft_strlen(const char *str)
{
    int count;

    count = 0;
    while (*str)
    {
        count ++;
        str ++;
    }
    return (count);
}

long ft_atol(char *str)
{
	int		index;
	int		sign;
	long	result;

	index = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[index]) == 0)
		index ++;
	if (ft_issign(str[index]) == 0)
	{
		if (str[index] == '-')
			sign *= -1;
		index ++;
	}
	while (str[index] && ft_isdigit(str[index]) == 0)
	{
		result = (result * 10) + (str[index] - '0');
		index ++;
	}
	return (result * sign);
}

int	count_input_elements(char *str)
{
	int	i;
	int	nele;

	nele = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ft_issign(str[i]))
		{
			nele ++;
		}
		while (str[i] && ft_isdigit(str[i]))
			i ++;
		while (str[i] && ft_isspace(str[i]))
			i ++;
	}
	return (nele);
}

int get_len_str(char *str)
{
	int	index;

	index = 0;
	while (str[index] && !ft_isspace(str[index]))
		index ++;
	return (index);
}

int	parse_single_input(char *str,long *tab)
{
	char **div;
	int	index;

	index = 0;
	div = ft_split(str,' ');

	while (div[index])
	{
		long res = ft_atol(div[index]);
		tab[index] = ft_atol(div[index]);
		if (tab[index] > INT_MAX || tab[index] < INT_MIN)
		{
			free_pp(div);
			return (1);
		}
		index ++;
	}
	free_pp(div);
	return (0);
}

int	parse_mul_input(char *str, long *tab)
{
	int		index;
	long	num;
	int		n_elements;

	if (!str)
		return (1);
	n_elements = count_input_elements(str);
    while (str[index] && (!ft_issign(str[index]) || !ft_isdigit(str[index])))
		index ++;
	if (!str[index])
		return (-1);
	num = ft_atol(&str[index]);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	tab[n_elements - 1] = num;
	n_elements --;

	return (0);
}