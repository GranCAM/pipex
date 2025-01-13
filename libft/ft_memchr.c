/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:39:08 by carbon-m          #+#    #+#             */
/*   Updated: 2024/09/30 17:18:19 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*src;

	src = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
			return (&src[i]);
		++i;
	}
	return (NULL);
}
/* 
int main(void)
{
	char *s ="Esta casa es una ruina";
	int	c = 99;
	int	n = 10;
	printf("%p\n",memchr(s,c,n));
	printf("%p\n",ft_memchr(s,c,n));
	return(0);
} */