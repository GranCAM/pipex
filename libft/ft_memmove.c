/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:34:23 by carbon-m          #+#    #+#             */
/*   Updated: 2024/10/02 19:50:56 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_move(const char *s, char *d, size_t n)
{
	size_t	i;

	i = 0;
	if (d > s)
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (dest == NULL && src == NULL && n != 0)
		return (0);
	d = (char *)dest;
	s = (const char *)src;
	d = ft_move(s, d, n);
	return (dest);
}
/* 
int	main(void)
{
	char str[] = "hola a todos";
	char *dest;
	int	n = 9;
	printf("%s \n",str);
	printf("%s \n",dest);
	printf("%s \n",(char *) ft_memmove(dest,str,n));
	printf("%s \n",str);
	printf("%s \n",dest);
	printf("%s \n",(char *) memmove(dest,str,n));
	printf("%s \n",str);
	printf("%s \n",dest);
	return (0);
}  */