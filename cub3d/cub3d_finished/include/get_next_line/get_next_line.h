/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:49:19 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/26 12:06:51 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	*ft_calloc_gnl(size_t count, size_t size);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
size_t	ft_strlen_gnl(const char *s);

#endif
