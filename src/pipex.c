/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:02:20 by carbon-m          #+#    #+#             */
/*   Updated: 2025/01/13 13:17:38 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **env)
{
	int		pipefd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("\n./pipex file_input cmd cmd file_output\n\n", 2);
		exit (-1);
	}
	if (pipe(pipefd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		child(argv, pipefd, env);
	else
		parent(argv, pipefd, env);
}

void	child(char *argv[], int *pipefd, char **env)
{
	int		fd;

	fd = open_flags(argv[1], 0);
	dup2(fd, 0);
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	process(argv[2], env);
}

void	parent(char *argv[], int *pipefd, char **env)
{
	int		fd;

	fd = open_flags(argv[4], 1);
	dup2(fd, 1);
	dup2(pipefd[0], 0);
	close(pipefd[1]);
	process(argv[3], env);
}

void process(char *argv, char **env)
{
	int ret;
	char *path;
	char **command;

	command = ft_split(argv, ' ');
	path = check_path();
	ret = 0;
	ret = execve(path, command, **env);
	if (ret == -1)
	{
		ft_putstr_fd("\npath/command not found\n\n", 2);
		exit (-1);
	}
}
