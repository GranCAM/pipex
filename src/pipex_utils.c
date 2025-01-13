/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:35:29 by carbon-m          #+#    #+#             */
/*   Updated: 2025/01/13 18:54:43 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{
	char	*envar;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i])
	{
		while (env[i][j] != '=')
			++j;
		envar = ft_substr(env[i], 0, j);
		if (ft_strncmp(envar, "PATH", 4) == 0)
			return (env[i] + j + 1);
		++i;
	}
	exit (NULL);
}

char	*check_path(char *command, char **env)
{
	char	*path;
	char	**split_path;

	path = get_path(env);
	return (path);
}

int	open_flags(char *argv, int proc)
{
	int	fd;

	fd = 0;
	if (proc == 0)
		fd = open(argv, O_RDONLY, 0777);
	if (proc == 0)
		fd = open(argv, O_CREAT, O_WRONLY, O_TRUNC, 0777);
	if (fd == -1)
		exit (-1);
	return (fd);
}
