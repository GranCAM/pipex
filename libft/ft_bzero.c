/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:32:11 by carbon-m          #+#    #+#             */
/*   Updated: 2024/09/27 19:19:14 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset((unsigned char *) s, 0, n);
}
/* 
int	main(void)
{
	char str[100] = "hola a todos";
	int	n = 4;
	printf("%s \n",str);
	ft_bzero(str,n);
	printf("%c \n",str[5]);
	bzero(str,n);
	printf("%s \n",str);
	return (0);
} */