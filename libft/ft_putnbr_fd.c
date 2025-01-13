/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:22:32 by carbon-m          #+#    #+#             */
/*   Updated: 2024/09/28 17:00:18 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = (long)n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
		num = num % 10;
	}
	ft_putchar_fd(num + 48, fd);
}
/* 
int	main(void)
{
	int n = 12249;
	int	fd = 1;
	char	jump = '\n';
	ft_putnbr_fd(n,fd);
	write(1,&jump,1);
	return(0);
} */