/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:11:18 by carbon-m          #+#    #+#             */
/*   Updated: 2024/09/27 18:38:11 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/* 
#include <stdio.h>

int	main(void)
{
	int c;
	c = 100;
	printf("%d\n",toupper(c));
	printf("%d\n",ft_toupper(c));
	return (0);
} */