/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:31:54 by carbon-m          #+#    #+#             */
/*   Updated: 2025/06/02 20:24:28 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char **env)
{
	int	fds[2];
	int	i;
	
	if (argc < 5 || argv[1][0] == 0 || argv[4][0] == 0)
		return (ft_putstr_fd(MSSG_INPUT, 2), 1);
	fds[1] = open_flags(argv[1], 0);
	i = 1;
	if (fds[1] != -1)
		dup2(fds[1], STDIN_FILENO);
	while (++i < argc - 2)
	{
		ft_putstr_fd("hace hijos \n", 2);
		child(argv, env, i);
	}
	fds[0] = open_flags(argv[argc - 1], 1);
	dup2(fds[0], STDOUT_FILENO);
	process(argv, env, i);
	return (0);
}

void	process(char **argv, char **env, int num)
{
	char	**command;
	char	*path;

	command = get_arg(argv, num);
	path = check_path (argv[num], env, command);
	ft_putstr_fd("CASI\n", 2);
	ft_putstr_fd(path, 2);
	if (execve(path, command, env) == -1)
	{
		ft_frematrix (command);
		perror("\npath/command not found\n\n");
		exit (-1);
	}
}


void	child(char **argv, char **env, int num)
{
	pid_t	pid;
	int		fd[2];

	if (argv[num][0] == 0)
	{
		ft_putstr_fd("zsh: permission denied:\n", 2);
		exit(127);
	}
	if (pipe(fd) == -1)
		error_msg("Failed to create the pipe");
	pid = fork();
	if (pid == -1)
		error_msg("Failed to create the fork");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		process(argv, env, num);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
		ft_putstr_fd("ACABA LOL \n", 2);
	}
}

void	error_msg(char *msg)
{
	perror(msg);
	exit (1);
}

int	open_flags(char *argv, int proc)
{
	int	fd;

	if (proc == 0)
		{fd = open(argv, O_RDONLY, 0644);
		if (fd == -1)
		{
			perror("Infile not existing / not workable");
		}}
	if (proc == 1)	
		{fd = open(argv, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror("outfile not workable");
			exit (1);
		}}
	if (proc == 2)	
		{fd = open(argv, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd == -1)
		{
			perror("Failed management of here_doc");
			exit (1);
		}}
	return (fd);
}
