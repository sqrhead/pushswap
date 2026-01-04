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
	long	result;
	int		sign;

	result = 0;
	sign = 1;

	if(*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str ++;
	}
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str ++;
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
			while (ft_isdigit(str[i]))
				i ++;
		}
		i ++;
	}
	return (nele);
}

int	parse_single_input(char *str,int *tab)
{
    static int	index = 0;
    long		num;
	int			n_elements;

	if (!str)
		return (1);
	n_elements = count_input_elements(str);
    while (str[index] && (!ft_issign(str[index]) || !ft_isdigit(str[index])))
        index ++;
	if (!str[index])
		return (-1);
	num = ft_atol(str[index]);
	if (num > INT_MAX || num < INT_MIN)
		return (1);

	n_elements = n_elements - index - 1; // index unusable if modified to update realt position
	tab[n_elements - 1] = num;
	return (0);

}

int	parse_mul_input(char *str, int *tab)
{
	int		index;
	long	num;
	int		n_elements;

	if (!str)(
		return (1);
	n_elements = count_input_elements(str);
    while (str[index] && (!ft_issign(str[index]) || !ft_isdigit(str[index])))
		index ++;
	if (!str[index])
		return (-1);
	num = ft_atol(str[index]);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	tab[n_elements - 1] = num;
	n_elements --;
}

int	check_double(int *tab)
{

}