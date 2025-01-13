/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:11:48 by carbon-m          #+#    #+#             */
/*   Updated: 2024/10/02 15:02:50 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	i = ft_strlen((char *)src);
	if (size == 0)
		return (i);
	while ((src[j] != 0) && (j < (size - 1)))
	{
		dst[j] = src [j];
		++j;
	}
	dst[j] = '\0';
	return (i);
}
/* 
int	main(void)
{
	char	*src = "Hola el que aprende japones y lo pronuncia muy bien";
	char	dst[] = "Hola holita tu, que tal estas";
	//unsigned int	size = sizeof(dst);
	unsigned int size = 51;
	printf("%s \n",dst);
	printf("%lu \n",ft_strlcpy(dst,src,size));
	printf("%s \n",dst);
	return (0);
}*/