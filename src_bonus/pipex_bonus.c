/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon <carbon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:31:54 by carbon-m          #+#    #+#             */
/*   Updated: 2025/06/01 19:15:15 by carbon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char **env)
{
	if (argc <= 5 || argv[1][0] == 0 || argv[4][0] == 0)
	{
		ft_putstr_fd(MSSG_INPUT, 2);
		exit (-1);
	}
	child(argv, env, 0);
	child(argv, env, 1);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
	return (0);
}

void	child(char **argv, char **env, int proc)
{
	int		fd;
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		exit(-1);
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
		fd = open_flags(argv[1], proc);
		dup2(fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(fd);
		close(pipefd[0]);
		close(pipefd[1]);
		process(argv, env, 2);
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

int	open_flags(char *argv, int proc)
{
	int	fd;

	if (proc == 0)
		fd = open(argv, O_RDONLY, 0644);
	if (proc == 1)
		fd = open(argv, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (proc == 2)
		fd = open(argv, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		perror("Infile not existing / outfile not workable");
		exit (1);
	}
	return (fd);
}


void	here_doc(char **argv, int argc)
{
	int	i;

	i = 0;
	
}

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}
