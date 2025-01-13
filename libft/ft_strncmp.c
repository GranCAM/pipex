/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:38:25 by carbon-m          #+#    #+#             */
/*   Updated: 2024/09/30 18:22:26 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1t;
	unsigned char	*s2t;

	s1t = (unsigned char *) s1;
	s2t = (unsigned char *) s2;
	i = 0;
	while ((s1t[i] != 0 || s2t[i] != 0) && i < n)
	{
		if (s1t[i] != s2t[i])
		{
			return ((s1t[i] - s2t[i]));
		}
		++i;
	}
	return (0);
}
/* 
int	main(void)
{
	char s1[] = "remo";
	char s2[] = "romulo y remo, padres fundadores";
	unsigned int	n;

	n = 20;
	printf("%d \n",ft_strncmp("abcdef", "abc\375xx", 5));
	printf("%d \n",strncmp("abcdef", "abc\375xx", 5));
	return (0);
} */
