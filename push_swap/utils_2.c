/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 00:28:23 by sede-los          #+#    #+#             */
/*   Updated: 2024/04/18 00:28:26 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_min(t_stack *a)
{
    int i;

    i = a->nbr;
    while(a)
    {
        if(i > a->nbr)
            i = a->nbr;
        a = a->next;
    }
    return (i);
    }

int ft_max(t_stack *a)
{
    int i;

    i =  a->nbr;
    while(a)
    {
        if(i < a->nbr)
            i = a->nbr;
        a  = a->next;
    }
    return (i);
}

int ft_stack_size(t_stack *stack)
{
    int i;

    i = 0;
    while(stack)
    {
        i++;
        stack = stack->next;
    }
    return (i); 
}

t_stack *ft_stacklast(t_stack *stack)
{
    while (stack && stack->next)
	stack = stack->next;
	return (stack);
}