/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:31:54 by carbon-m          #+#    #+#             */
/*   Updated: 2025/06/03 21:01:29 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char **env)
{
	int	fds[2];
	int	i;
	
	if (argc < 5 || argv[1][0] == 0 || argv[argc - 1][0] == 0 || ft_strlen(argv[argc - 2]) == 0)
		return (ft_putstr_fd(MSSG_INPUT, 2), 1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 2;
		fds[0] = open_flags(argv[argc - 1], 2);
		here_doc(argv[2]);
	}
	else
	{
		fds[1] = open_flags(argv[1], 0);
		i = 1;
		dup2(fds[1], STDIN_FILENO);
		fds[0] = open_flags(argv[argc - 1], 1);
	}
	while (++i < argc - 2)
		child(argv, env, i);
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
	{
		fd = open(argv, O_RDONLY, 0644);
		if (fd == -1)
			ft_putendl_fd("Infile not existing / not workable", 2);
	}
	if (proc == 1)	
	{

		fd = open(argv, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
			error_msg("outfile not workable");
	}
	if (proc == 2)	
	{
		fd = open(argv, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd == -1)
			error_msg("Failed management of here_doc");
	}
	return (fd);
}
