/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:33:10 by carbon-m          #+#    #+#             */
/*   Updated: 2025/05/28 15:38:21 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*read_until_jump(char *s_buffer, int fd)
{
	char	*tr_buffer;
	int		readed;

	tr_buffer = ft_calloc_gnl (1, 10 + 1);
	if (!tr_buffer)
		return (NULL);
	while (!ft_strchr(s_buffer, 10))
	{
		readed = read (fd, tr_buffer, 10);
		if (readed < 0)
		{
			free(s_buffer);
			free(tr_buffer);
			return (NULL);
		}
		if (readed == 0)
			break ;
		tr_buffer[readed] = 0;
		s_buffer = ft_strjoin_free(s_buffer, tr_buffer);
	}
	free(tr_buffer);
	return (s_buffer);
}

char	*full_line(char *s_buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (!s_buffer[i])
		return (NULL);
	while (s_buffer[i] != 10 && s_buffer[i])
		++i;
	line = ft_calloc_gnl(1, i + 2);
	if (!line)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		line[j] = s_buffer[j];
		++j;
	}
	return (line);
}

char	*rest_buffer(char *s_buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	while (s_buffer[i] && s_buffer[i] != '\n')
		i++;
	if (!s_buffer[i])
	{
		free(s_buffer);
		return (NULL);
	}
	new_buffer = ft_calloc_gnl((ft_strlen(s_buffer) - i + 1), sizeof(char));
	i += 1;
	j = 0;
	while (s_buffer[i - 1])
	{
		new_buffer[j] = s_buffer[i];
		++i;
		++j;
	}
	free(s_buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*s_buffer;
	char		*line;

	if (!s_buffer)
		s_buffer = ft_calloc_gnl (1, 10 + 1);
	if (fd < 0 || 10 <= 0)
		return (NULL);
	s_buffer = read_until_jump(s_buffer, fd);
	if (!s_buffer)
		return (NULL);
	line = full_line(s_buffer);
	s_buffer = rest_buffer(s_buffer);
	return (line);
}

char	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	char	*res;
	size_t	i;
	size_t	len;

	len = size * nmemb;
	res = malloc(len);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = 0;
		++i;
	}
	return (res);
}
