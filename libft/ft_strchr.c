/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:38:35 by carbon-m          #+#    #+#             */
/*   Updated: 2024/10/21 17:45:16 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cast;

	cast = (char) c;
	i = 0;
	if (cast == 0)
		return ((char *) &s[ft_strlen((char *)s)]);
	while (s[i])
	{
		if (s[i] == cast)
			return ((char *) &s[i]);
		++i;
	}
	return (0);
}
/* 
int	main(void)
{
	const char s[100] = "Esta casa es una ruina";
	int	c = '\n';
	printf("%s\n",strchr(s,c));
	printf("%s\n",ft_strchr(s,c));
	return (0);
} */