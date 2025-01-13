/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:20:25 by carbon-m          #+#    #+#             */
/*   Updated: 2024/09/27 18:43:50 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
/* 
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int c;
	c = 100;
	printf("%d\n",tolower(c));
	printf("%d\n",ft_tolower(c));
	return (0);
} */