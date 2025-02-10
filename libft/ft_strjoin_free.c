/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:42:54 by carbon-m          #+#    #+#             */
/*   Updated: 2025/02/03 14:48:19 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		len;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen((char *)s1);
	i = ft_strlen((char *)s2);
	res = malloc(sizeof(char) * (len + i) + 1);
	if (!res)
		return (0);
	i = -1;
	while (s1[++i] != 0)
		res[i] = s1[i];
	i = -1;
	while (s2[++i] != 0)
		res[len + i] = s2[i];
	res[len + i] = 0;
	free (s1);
	return (res);
}
