/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:35:29 by carbon-m          #+#    #+#             */
/*   Updated: 2025/02/10 19:00:08 by carbon-m         ###   ########.fr       */
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
	i = 0;
	while (split_path[i])
	{
		path = ft_strdup(split_path[i]);
		path = ft_strjoin_free(path, "/");
		path = ft_strjoin_free(path, command_clean[0]);
		if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
		{
			ft_frematrix(split_path);
			return (path);
		}
		free(path);
		++i;
	}
	return (ft_frematrix(command_clean), ft_frematrix(split_path),
		ft_putstr_fd("zsh: command not found :", STDERR_FILENO),
		ft_putstr_fd(command, STDERR_FILENO),
		ft_putendl_fd("", STDERR_FILENO), exit(127), NULL);
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

int	open_flags(char *argv, int proc)
{
	int	fd;

	if (proc == 0)
		fd = open(argv, O_RDONLY, 0644);
	if (proc == 1)
		fd = open(argv, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Infile not existing / outfile not workable");
		exit (1);
	}
	return (fd);
}
