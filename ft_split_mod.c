#include "push_swap.h"

int	word_len(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

int	words_num(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			words++;
		i++;
	}
	return (words);
}

char	**free_pp(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	return (NULL);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	count;
	size_t	index;

	count = 0;
	index = 0;
	while (src[count] != '\0')
		count ++;
	if (size > 0)
	{
		while (src[index] != '\0' && index < size - 1)
		{
			dest[index] = src[index];
			index ++;
		}
		dest[index] = '\0';
	}
	return (count);
}


char	**ft_split(char const *s, char c)
{
	int		j;
	char	*s_cpy;
	char	**splits;

	j = 0;
	s_cpy = (char *)s;
	if (s == NULL)
		return (NULL);
	splits = (char **)malloc((words_num(s, c) + 1) * sizeof(char *));
	if (!splits)
		return (NULL);
	while (j < words_num(s, c) && s_cpy)
	{
		while (*s_cpy == c)
			s_cpy++;
		splits[j] = malloc((word_len(s_cpy, c) + 1) * sizeof(char));
		if (!splits[j])
			return (free_pp(splits));
		ft_strlcpy(splits[j], s_cpy, word_len(s_cpy, c) + 1);
		s_cpy += word_len(s_cpy, c) + 1;
		j++;
	}
	splits[j] = NULL;
	return (splits);
}