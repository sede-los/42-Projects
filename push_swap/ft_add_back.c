/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:07:52 by sede-los          #+#    #+#             */
/*   Updated: 2024/04/17 19:08:17 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_add_back(t_stack **stack,  t_stack *new_stack)
{
    if (!stack)
        return;
    if (!*stack)
        *stack = new_stack;
    else
        (ft_lstlast(*stack))->next  = new_stack;
}