/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:02:20 by carbon-m          #+#    #+#             */
/*   Updated: 2025/02/11 12:24:10 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **env)
{
	int		pipefd[2];

	if (argc != 5 || argv[1][0] == 0 || argv[4][0] == 0)
	{
		ft_putstr_fd("\n./pipex file_input cmd cmd file_output\n\n", 2);
		exit (-1);
	}
	if (pipe(pipefd) == -1)
		exit(-1);
	child(argv, pipefd, env);
	child2(argv, pipefd, env);
	close (pipefd[0]);
	close (pipefd[1]);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
	return (0);
}

void	child(char **argv, int *pipefd, char **env)
{
	int		fd;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Failed fork: ");
		exit(-1);
	}
	if (pid == 0)
	{
		if (argv[2][0] == 0)
		{
			ft_putstr_fd("zsh: permission denied:\n", 2);
			exit(127);
		}
		fd = open_flags(argv[1], 0);
		dup2(fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(fd);
		close(pipefd[0]);
		close(pipefd[1]);
		process(argv, env, 2);
	}
}

void	child2(char *argv[], int *pipefd, char **env)
{
	int		fd;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Failed fork: ");
		exit(-1);
	}
	if (pid == 0)
	{
		if (argv[3][0] == 0)
		{
			ft_putstr_fd("zsh: permission denied:\n", 2);
			exit(127);
		}
		fd = open_flags(argv[4], 1);
		dup2(fd, STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		close(fd);
		close(pipefd[0]);
		close(pipefd[1]);
		process(argv, env, 3);
	}
}

void	process(char **argv, char **env, int num)
{
	char	**command;
	char	*path;

	command = get_arg(argv, num);
	path = check_path (argv[num], env, command);
	if (execve(path, command, env) == -1)
	{
		ft_frematrix (command);
		perror("\npath/command not found\n\n");
		exit (-1);
	}
}
