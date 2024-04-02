/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:57:06 by sede-los          #+#    #+#             */
/*   Updated: 2024/03/16 00:26:44 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*custom_free(char **str);
char	*free_stored_line(char *fd_storage);
char	*get_line(char *fd_storage);
char	*read_line(int fd, char *fd_storage);
char	*get_next_line(int fd);

char	*custom_ft_strjoin(char *s1, char *s2);
char	*custom_ft_substr(char *s, unsigned int start, size_t len);
char	*custom_ft_strchr(char *str, int c);
int		custom_ft_strlen(char *str);

#endif
