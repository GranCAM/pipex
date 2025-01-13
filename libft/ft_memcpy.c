/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:32:44 by carbon-m          #+#    #+#             */
/*   Updated: 2024/09/30 11:13:17 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int					i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	if (!src && !dest)
		return (0);
	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	while (n != 0)
	{
		d[i] = s[i];
		++i;
		--n;
	}
	return (d);
}
/* 
int	main(void)
{
	char str[100] = "hola a todos";
	char dest[100];
	int	n = 4;
	printf("%s \n",str);
	printf("%s \n",ft_memcpy(dest,str,n));
	printf("%s \n",memcpy(dest,str,n));
	return (0);
} */