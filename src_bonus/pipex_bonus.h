/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:45:21 by carbon-m          #+#    #+#             */
/*   Updated: 2025/06/03 16:20:02 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
# define MSSG_INPUT "\nPIPEX BONUS usage\n\n \
./pipex_bonus here_doc Limiter cmd cmd ... cmd file_output\n\n \
./pipex_bonus file_input cmd cmd ... cmd file_output\n\n"

void	child(char **argv, char **env, int num);
void	process(char **argv, char **env, int num);
int		open_flags(char *argv, int proc);
char	*check_path(char *command, char **env, char **command_clean);
char	*get_path(char **env);
char	**get_arg(char **argv, int num);
void	errorpath(char *command, char **command_clean, char **split_path, int way);
char	*read_until_jump(char *s_buffer, int fd);
char	*full_line(char *s_buffer);
char	*rest_buffer(char *s_buffer);
char	*get_next_line(int fd);
char	*ft_calloc_gnl(size_t nmemb, size_t size);
void	error_msg(char *msg);
void	here_doc(char *limiter);

#endif