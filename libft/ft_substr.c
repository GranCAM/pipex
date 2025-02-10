/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:19:54 by carbon-m          #+#    #+#             */
/*   Updated: 2025/02/06 18:17:35 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s)
		return (NULL);
	if (len == ft_strlen(s) && start == 0)
		return (res = ft_strdup(s), res);
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	res = ft_calloc (len + 2, 1);
	if (!res)
		return (0);
	if ((size_t)start >= ft_strlen((char *)s) || len == 0)
	{
		ft_strlcpy(res, "", 1);
		res[len + 1] = 0;
		return (res);
	}
	if (ft_strlcpy(res, &s[start], (len + 1)))
	{
		res[len + 1] = 0;
		return (res);
	}
	return (0);
}
/* 
int main(void)
{
	const char	*s = "Hola holita holete";
	size_t	len = 6;
	unsigned int	start = 5;
	//printf("%s \n",substr(s,start,len));
	printf("%s \n",ft_substr(s,start,len));
	return (0);
} */