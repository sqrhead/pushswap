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
	int	index;
	int	sign;
	int	result;	

	index = 0;
	sign = 1;
	result = 0;
	if (ft_issign(str[index]))
	{
		if (str[index] == '-')
			sign *= -1;
		index ++;
	}
	while (str[index] && ft_isdigit(str[index]))
	{
		result = (result * 10) + str[index] - '0';
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

int	parse_single_input(char *str,int *tab)
{
    static int	index = 0;
    long		num;
	int			n_elements;

	if (!str)
		return (1);
	n_elements = count_input_elements(str);

	while (n_elements > 0)
	{
		while (str[index] && (!ft_issign(str[index]) || !ft_isdigit(str[index])))
			index ++;
		if (!str[index])
			return (1);
		num = ft_atol(&str[index]);
		printf("num %ld\n",num);
		printf("len %i\n",get_len_str(&str[index])); // Error : 
		index += get_len_str(&str[index]);
		if (num > INT_MAX || num < INT_MIN)
			return (1);
		tab[n_elements - 1] = num;
		n_elements --;
	}	
	return (0);

}

int	parse_mul_input(char *str, int *tab)
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