/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:21:00 by carbon-m          #+#    #+#             */
/*   Updated: 2024/10/09 12:25:10 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*res;

	i = 0;
	if (!s || !f)
		return (NULL);
	res = (char *) malloc((sizeof(char) * ft_strlen((char *) s)) + 1);
	if (!res)
		return (NULL);
	while (s[i] != 0)
	{
		res[i] = f(i, s[i]);
		++i;
	}
	res[i] = 0;
	return (res);
}
