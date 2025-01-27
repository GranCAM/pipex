/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:35:29 by carbon-m          #+#    #+#             */
/*   Updated: 2025/01/27 19:03:08 by carbon-m         ###   ########.fr       */
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

char	*check_path(char *command, char **env, int format, char *command_clean)
{
	char	*path;
	char	**split_path;
	int		i;

	write(2,"in checkpath\n", 13);
	if (format == 1)
	{
		if (access(command, F_OK) == 0 && access(command, X_OK) == 0)
			return (command);
		else
			exit (-1);
	}
	split_path = ft_split(get_path(env), ':');
	write(2, "Getpath done\n",13);
	i = 0;
	while (split_path[i])
	{
		path = ft_strdup(split_path[i]);
		path = ft_strjoin(path, "/");
		path = ft_strjoin(path, command_clean);
		if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
		{
			write(2, "Path:",5);
			write(2, path, ft_strlen(path));
			write(2, "\n",1);
			ft_frematrix(split_path);
			return (path);
		}
		free(path);
		++i;
	}
	ft_frematrix(split_path);
	perror("LA CAGASTE");
	exit(-1);
	return (NULL);
}

char	**get_arg(char *argv, int format)
{
	char	**command;
	char	**command_f2;
	int		i;

	command = ft_calloc(sizeof(char *), 2);
	if (format == 2)
		command = ft_split(argv, ' ');	
	else
	{
		command_f2 = ft_split(argv, '/');
		i = 0;
		while (command_f2[i])
			++i;
		if (ft_strchr(command_f2[i - 1], ' '))
			command = ft_split(command_f2[i - 1], ' ');
		else
			command[0] = ft_strdup(command_f2[i - 1]);
		ft_frematrix(command_f2);
	}
	return (command);
}
