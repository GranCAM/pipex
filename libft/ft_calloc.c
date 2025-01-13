/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:22:48 by carbon-m          #+#    #+#             */
/*   Updated: 2024/10/07 15:21:35 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < size * nmemb)
	{
		ptr[i] = 0;
		++i;
	}
	return (ptr);
}
/* 
int	main(void)
{
	int	size = 4;
	int num = 2;
	int i = 0;
	int *a = calloc(num,size);
	int *b = ft_calloc(num,size);
	while(a[i] <= 4)
	{
		printf("%d \n",a[i]);
		++i;
	}
	printf("\n");
	i = 0;
	while(a[i] <= 4)
	{
		printf("%d \n",b[i]);
		++i;
	}
	return (0);
} */