/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:35:29 by carbon-m          #+#    #+#             */
/*   Updated: 2025/01/14 15:18:33 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_flags(char *argv, int proc)
{
	int	fd;

	if (proc == 0)
		fd = open(argv, O_RDONLY, 0777);
	else if (proc == 1)
		fd = open(argv, O_CREAT, O_WRONLY, O_TRUNC, 0777);
	if (fd == -1)
		exit (-1);
	return (fd);
}

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

char	*check_path(char *command, char **env, int format)
{
	char	*path;
	char	**split_path;
	int		i;
	char	*path_command;

	if (format == 1)
	{
		if (access(command, F_OK) == 0 && access(command, X_OK) == 0)
			return (command);
	}
	split_path = ft_split(get_path(env), ':');
	i = 0;
	while (split_path[i])
	{
		path = ft_strjoin(path, split_path[i]);
	}
	return (path);
}

char	*get_arg(char *argv, int format)
{
	char	**command;
	int		i;
	
	if (format == 1)
	{
		command = ft_split(argv, '/');
		i = 0;
		while (command[i])
			++i;
		return (command[i - 1]);
	}
	else
	{
		command = ft_split(argv, ' ');
		return (command[0]);
	}
	return (NULL);
}
