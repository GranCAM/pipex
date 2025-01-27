/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:35:29 by carbon-m          #+#    #+#             */
/*   Updated: 2025/01/21 19:12:42 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{
	int		i;
	
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i]  + 5);
		++i;
	}
	return (NULL);
}

char	*check_path(char *command, char **env, int format)
{
	char	*path;
	char	**split_path;
	int		i;

	if (format == 1)
	{
		if (access(command, F_OK) == 0 && access(command, X_OK) == 0)
			return (command);
	}
	split_path = ft_split(get_path(env), ':');
	i = 0;
	while (split_path[i])
	{
		path = ft_strjoin(path, "/");
		path = ft_strjoin(path, split_path[i]);
	}
	ft_frematrix(split_path);
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

char	*flags_arg(char *argv)
{
	int		i;
	char	*flags;

	i = 0;
	while (argv[i] != ' ')
		++i;
	flags = ft_strdup(argv + i);
	return (flags);
}
