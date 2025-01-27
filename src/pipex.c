/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:02:20 by carbon-m          #+#    #+#             */
/*   Updated: 2025/01/27 11:06:40 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **env)
{
	int		pipefd[2];
	pid_t	pid;

	if (argc != 5 || argv[1][0] == 0 || argv[2][0] == 0 || argv[3][0] == 0 || argv[4][0] == 0)
	{
		ft_putstr_fd("\n./pipex file_input cmd cmd file_output\n\n", 2);
		exit (-1);
	}
	if (pipe(pipefd) == -1)
		exit(-1);
	printf("%d %d \n",pipefd[0], pipefd[1]);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		child(argv, pipefd, env);
	else
	{
		waitpid(pid, NULL, 0);
		child2(argv, pipefd, env);
	}
}

void	child(char *argv[], int *pipefd, char **env)
{
	int		fd;

	close(pipefd[0]);
	fd = open_flags(argv[1], 0);
	dup2(fd, 0);
	close(fd);
	printf("%d %d \n",pipefd[0], pipefd[1]);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	process(argv[2], env);
}

void	child2(char *argv[], int *pipefd, char **env)
{
	int		fd;

	close(pipefd[1]);
	fd = open_flags(argv[4], 0);
	dup2(fd, 1);
	close(fd);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	process(argv[3], env);
}

void	process(char *argv, char **env)
{
	char	**command;
	int		command_format;

	command = ft_calloc(3 * sizeof(char *), 1);
	if (ft_strchr(argv, '/'))
		command_format = 1;
	else
		command_format = 2;
	command[1] = get_arg(argv, command_format);
	command[0] = check_path (argv, env, command_format);
	if (ft_strchr(argv, ' '))
		command[2] = flags_arg(argv);
	if (execve(command[0], command, env) == -1)
	{
		perror("\npath/command not found\n\n");
		exit (-1);
	}
}

int	open_flags(char *argv, int proc)
{
	int	fd;

	if (proc == 0)
		fd = open(argv, O_RDONLY, 0777);
	if (proc == 1)
		fd = open(argv, O_CREAT | O_WRONLY | O_TRUNC , 0777);
	if (fd == -1)
		exit (-1);
	return (fd);
}
