/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:35:47 by carbon-m          #+#    #+#             */
/*   Updated: 2024/09/27 18:30:39 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*string;

	string = (char *) str;
	i = 0;
	while (i < n)
	{
		string[i] = c;
		++i;
	}
	return (string);
}
/* 
int	main(void)
{
	char str[100] = "hola a todos";
	int	n = 4;
	int	c = 82;
	printf("%s \n",str);
	ft_memset(str,c,n);
	printf("%s \n",str);
	memset(str,c,n);
	printf("%s \n",str);
	return (0);
} */