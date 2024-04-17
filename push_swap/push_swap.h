/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:57:56 by sede-los          #+#    #+#             */
/*   Updated: 2024/04/17 18:02:27 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"

typedef struct s_stack
{
    long    nbr;
    long    index;
    struct s_stack *next;
    struct s_stack *prev;
}               t_stack;

t_stack     *ft_process(int argc, char **argv);
void        ft_error(void);
int         ft_atoi2(const char *str);
t_stack     *ft_new_stack(int content);
void	    ft_freestr(char **lst);
#endif
