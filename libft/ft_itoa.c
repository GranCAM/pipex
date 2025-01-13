/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:20:49 by carbon-m          #+#    #+#             */
/*   Updated: 2024/10/15 13:47:45 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_minnum(int n, char *num)
{
	if (n == -2147483648)
	{
		num[10] = '8';
		n = n / 10;
	}
	return (n);
}

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		++i;
	}
	while (n > 0)
	{
		n = n / 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*num;

	i = ft_count(n);
	num = malloc(i + 1);
	if (!num)
		return (0);
	num[i] = 0;
	if (n == -2147483648)
		--i;
	n = ft_minnum(n, num);
	if (n < 0)
	{
		n = -n;
		num[0] = '-';
	}
	while (n > 9)
	{
		num[i - 1] = (n % 10) + 48;
		n = n / 10;
		--i;
	}
	num[i - 1] = n + 48;
	return (num);
}
/* 
int	main(void)
{
	int	n;
	char	*res = ft_itoa(n);
	printf("%s \n",res),ft_itoa(n);
	return (0);
} */