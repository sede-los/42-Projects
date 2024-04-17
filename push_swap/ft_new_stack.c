/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:48:03 by sede-los          #+#    #+#             */
/*   Updated: 2024/04/17 18:48:05 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_new_stack(int content)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        ft_error();
    new->nbr = content;
    new->next = NULL;
    return (new);
}