/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:36:55 by carbon-m          #+#    #+#             */
/*   Updated: 2025/06/02 20:16:00 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_path(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		++i;
	}
	return (NULL);
}

char	*check_path(char *command, char **env, char **command_clean)
{
	char	*path;
	char	**split_path;
	int		i;

	if (access(command, F_OK) == 0 && access(command, X_OK) == 0)
		return (command);
	split_path = ft_split(get_path(env), ':');
	if (split_path == NULL)
		errorpath(command, command_clean, split_path, 1);
	i = 0;
	
	while (split_path[i])
	{
		path = ft_strdup(split_path[i]);
		path = ft_strjoin_free(path, "/");
		path = ft_strjoin_free(path, command_clean[0]);
		if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
			return (ft_frematrix(split_path), path);
		free(path);
		++i;
	}
	ft_putstr_fd("OK\n", 2);
	return (errorpath(command, command_clean, split_path, 2), NULL);
}

char	**get_arg(char **argv, int num)
{
	char	**command;
	char	**command_f2;
	int		i;

	if (!ft_strchr(argv[num], '/'))
	{
		command = ft_split(argv[num], ' ');
	}
	else
	{
		command_f2 = ft_split(argv[num], '/');
		i = 0;
		while (command_f2[i])
			++i;
		command = ft_split(command_f2[i - 1], ' ');
		ft_frematrix(command_f2);
	}
	return (command);
}

void	errorpath(char *command, char **command_clean, char **split_path, int way)
{
	if (command_clean)
		ft_frematrix(command_clean);
	if (split_path)
		ft_frematrix(split_path);
	if (way == 1)
	{
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": No such file or directory", 2);
	}
	else
	{
		ft_putstr_fd("zsh: command not found: ", 2);
		ft_putstr_fd(command, 2);
	}
	ft_putendl_fd("", 2);
	exit(127);
}
