/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:20:36 by carbon-m          #+#    #+#             */
/*   Updated: 2025/02/04 17:56:29 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcount(char const *s, char c)
{
	size_t	count_arr;
	int		i;

	count_arr = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != 0)
				i++;
			count_arr++;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (count_arr);
}

static char	**check(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = ft_calloc(sizeof(char *), (ft_strcount(s, c) + 1));
	if (!res)
		return (NULL);
	return (res);
}

static void	*ft_free(char **res, int count)
{
	int	i;

	i = 0;
	while (res[i] && i < count)
	{
		free (res[i]);
		++i;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		counter;

	i = 0;
	counter = 0;
	res = check (s, c);
	if (!res)
		return (NULL);
	while (s[i] != 0 && counter < ft_strcount(s, c))
	{
		j = 0;
		while (s[i] == c)
			++i;
		while (s[j + i] != c && s[j + i] != 0)
			++j;
		res[counter] = ft_substr(s, i, j);
		if (res[counter] == 0)
			return (ft_free(res, ft_strcount(s, c)));
		++counter;
		i = i + j;
	}
	res[counter] = 0;
	return (res);
}

/* int	main(void)
{
	const char *s ="Hello";
	char	c = ' ';
	char	**res;
	int	i = 0;
	res = ft_split(s,c);
	while (res[i] != 0)
	{
		printf(" %s \n", res[i]);
		i++;
	}
	return (0);
} */