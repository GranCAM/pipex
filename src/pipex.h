/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:45:21 by carbon-m          #+#    #+#             */
/*   Updated: 2025/01/13 17:33:48 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include<sys/types.h>
# include<sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>
# include "../libft/libft.h"

void	child(char *argv[], int *pipefd, char **env);
void	parent(char *argv[], int *pipefd, char **env);
void process(char *argv, char **env);
int	open_flags(char *argv, int proc);


#endif