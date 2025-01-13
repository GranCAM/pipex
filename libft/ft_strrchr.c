/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:37:51 by carbon-m          #+#    #+#             */
/*   Updated: 2024/09/30 11:43:56 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cast;
	char	*st;

	cast = (char)c;
	st = (char *)s;
	i = (ft_strlen(st) - 1);
	if (cast == 0)
		return ((char *) &s[i + 1]);
	while (i >= 0)
	{
		if (st[i] == cast)
			return (&(st[i]));
		--i;
	}
	return (NULL);
}
/* 
int	main(void)
{
	const char s[100] = "Esta casa es una ruina";
	int	c = 99;
	printf("%s\n",strrchr(s,c));
	printf("%s\n",ft_strrchr(s,c));
	return (0);
} */