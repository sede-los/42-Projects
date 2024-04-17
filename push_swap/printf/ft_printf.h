/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:53:18 by sede-los          #+#    #+#             */
/*   Updated: 2023/09/26 00:30:58 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>

int	ft_printf(char const *format, ...);
int	ft_printchr(int c);
int	ft_printstr(char *str);
int	ft_printnbr(long n, int base);
int	ft_printptr(char *ptr);
int	ft_printunsnbr(unsigned long n, int base);
int	ft_printhexmay(unsigned long n, int base);
int	ft_printhex(unsigned long n, int base);

#endif
