/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:36:59 by adavila-          #+#    #+#             */
/*   Updated: 2024/08/29 10:36:59 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		line_length(char *s);
char	*get_next_line(int fd);
char	*ft_strapp_g(char *s1, char *s2);
#endif