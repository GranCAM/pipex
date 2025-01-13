/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:22:58 by carbon-m          #+#    #+#             */
/*   Updated: 2024/10/09 12:51:52 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	i;

	res = malloc(ft_strlen(s) + 1);
	if (!res)
		return (0);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		++i;
	}
	res[i] = 0;
	return (res);
}
/* 
int	main(void)
{
	const char *str = "HOLA CARACOLA";
	char	*res1;
	char	*res2;
	res1 = strdup(str);
	printf("%s \n",res1);
	free(res1);
	res2 = ft_strdup(str);
	printf("%s \n",res2);
	free(res2);
	return (0);
} */