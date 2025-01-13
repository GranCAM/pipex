/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:39:23 by carbon-m          #+#    #+#             */
/*   Updated: 2024/10/02 17:44:15 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[i] == 0)
		return ((char *) big);
	while (big[i] != 0 && i < len)
	{
		while ((big[i + j] == little[j]) && little[j] != 0 && (i + j) < len)
			++j;
		if (little[j] == 0)
		{
			return ((char *) &big[i]);
		}
		j = 0;
		++i;
	}
	if (big[i] != 0)
		return (0);
	return (0);
}
/* 
int	main(void)
{
	char *big = "Esta casa ru es una ruina";
	char *little = "ruina ";
	size_t	len = 29;
	printf("%s \n",strnstr(big,little,len));
	printf("%s \n",ft_strnstr(big,little,len));
	return (0);
} */