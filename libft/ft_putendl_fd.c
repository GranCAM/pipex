/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:22:14 by carbon-m          #+#    #+#             */
/*   Updated: 2024/10/07 12:06:35 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		len;
	char	eol;

	if (!s)
		return ;
	eol = 10;
	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, &eol, 1);
}
/*
int	main(void)
{
	char *str = "hola holita";
	int	fd = 1;
	ft_putendl_fd(str,fd);
	return(0);
} */