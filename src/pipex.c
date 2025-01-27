/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:02:20 by carbon-m          #+#    #+#             */
/*   Updated: 2025/01/27 19:39:34 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **env)
{
	int		pipefd[2];
	pid_t	pid;
	pid_t	pid2;
	
	if (argc != 5 || argv[1][0] == 0 || argv[2][0] == 0 || argv[3][0] == 0 || argv[4][0] == 0)
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
	{	
		write(2, "child1 entra \n", ft_strlen(" child1 entra \n"));	
		child(argv, pipefd, env);
	}	
	else
	{
		waitpid(pid, NULL, 0);
		write(2, " child1 done \n", ft_strlen(" child1 done \n"));
		pid2 = fork();
		if (pid2 == -1)
			exit(-1);
		if (pid2 == 0)
		{
			write(2, "child2 entra \n", ft_strlen(" child2 entra \n"));	
			child2(argv, pipefd, env);
		}
	}
	write(2, " child2 done \n", ft_strlen(" child2 done \n"));
}

void	child(char **argv, int *pipefd, char **env)
{
	int		fd;

	close(pipefd[0]);
	fd = open_flags(argv[1], 0);
	dup2(fd, 0);
	close(fd);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	process(argv[2], env);
}

void	child2(char *argv[], int *pipefd, char **env)
{
	int		fd;

	close(pipefd[1]);
	fd = open_flags(argv[4], 1);
	dup2(fd, 1);
	close(fd);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	process(argv[3], env);
}

void	process(char *argv, char **env)
{
	char	**command;
	char	*path;
	int		command_format;

	write(2, "proceso dentro \n", 16);
	command = ft_calloc(2 * sizeof(char *), 1);
	if (ft_strchr(argv, '/'))
		command_format = 1;
	else
		command_format = 2;
	command = get_arg(argv, command_format);
	path = check_path (argv, env, command_format, command[0]);
	write(2, "before execve: ",ft_strlen("before execve: "));
	write(2, command[0],ft_strlen(command[0]));
	if (command[1])
		write(2, command[1],ft_strlen(command[1]));
	write(2, "\n",1);
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
		fd = open(argv, O_RDONLY, 0777);
	if (proc == 1)
		fd = open(argv, O_CREAT | O_WRONLY | O_TRUNC , 0644);
	if (fd < 0)
		exit (-1);
	return (fd);
}
