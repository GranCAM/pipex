/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:45:21 by carbon-m          #+#    #+#             */
/*   Updated: 2025/02/04 17:59:36 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"

void	child(char *argv[], int *pipefd, char **env);
void	child2(char *argv[], int *pipefd, char **env, pid_t *pid);
void	process(char **argv, char **env, int num);
int		open_flags(char *argv, int proc);
char	*check_path(char *command, char **env, char **command_clean);
char	*get_path(char **env);
char	**get_arg(char **argv, int num);
void	freall(char **all);

#endif