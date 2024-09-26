/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:36:12 by adavila-          #+#    #+#             */
/*   Updated: 2024/08/29 10:36:12 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H
# include "libft.h"

int		printchar(char c, int fd);
int		putchar_f(int c, int fd);
int		printstr(const char *s, int fd);
int		printaddr(void *addr, int fd);
int		printint(long n, int fd);
int		printuint(unsigned int u_int, int fd);
int		printhex(long n, char type, int fd);
int		uint_length(unsigned int n);
int		is_set_f(char c, char *set);
int		int_length(long int n);
int		hex_count(unsigned long n);
void	to_hex(unsigned long n, int mode, int fd);
void	putnbr_fd_f(long int n, int fd);
#endif