/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:20:23 by carbon-m          #+#    #+#             */
/*   Updated: 2024/10/07 17:31:35 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char s1_i, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == s1_i)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_char_in_set(s1[start], set))
		++start;
	while (ft_char_in_set(s1[end - 1], set))
		--end;
	res = ft_substr(s1, start, (end - start));
	return (res);
}
/* 
int	main(void)
{
	char const	*s1 = "hhhhlalalaslllllllllll";
	char	*set = "hola";
	char *res;
	res = ft_strtrim(s1,set);
	printf("%s \n",res);
	return (0);
} */