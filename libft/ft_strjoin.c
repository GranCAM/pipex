/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:20:05 by carbon-m          #+#    #+#             */
/*   Updated: 2024/10/07 12:14:24 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (res);
}
/* 
int main(void)
{
	char const *s1 = "Hola ";
	char const *s2 = "holita";
	char *s3 = ft_strjoin(s1,s2);
	return(0);
} */